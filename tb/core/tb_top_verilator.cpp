#include "svdpi.h"
#include "Vtb_top_verilator__Dpi.h"
#include "Vtb_top_verilator.h"
#include "verilated_vcd_c.h"
#include "verilated.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <exception>
#include <cstdio>
#include <cstdint>
#include <cerrno>

void dump_memory();
double sc_time_stamp();

static vluint64_t t = 0;
Vtb_top_verilator *top;

int main(int argc, char **argv, char **env)
{
    int status = 0;
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    top = new Vtb_top_verilator();

    svSetScope(svGetScopeFromName(
        "TOP.tb_top_verilator.riscv_wrapper_i.ram_i.dp_ram_i"));
    Verilated::scopesDump();

#ifdef VCD_TRACE
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("verilator_tb.vcd");
#endif
    top->fetch_enable_i = 1;
    top->clk_i          = 0;
    top->rst_ni         = 0;

    top->eval();
    dump_memory();

    while (!Verilated::gotFinish()) {
        if (t > 40)
            top->rst_ni = 1;
        top->clk_i = !top->clk_i;
	status = top->tests_failed_o;
        top->eval();
#ifdef VCD_TRACE
        tfp->dump(t);
#endif
        t += 5;
    }
#ifdef VCD_TRACE
    tfp->close();
#endif
    delete top;

    return status;
}

double sc_time_stamp()
{
    return t;
}

void dump_memory()
{
    errno = 0;
    std::ofstream mem_file;
    svLogicVecVal addr = {0, 0};

    mem_file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    try {
        mem_file.open("memory_dump.bin");
        for (size_t i = 0; i < 1048576; i++) {
            addr.aval    = i;
            uint32_t val = read_byte(&addr);
            mem_file << std::setfill('0') << std::setw(2) << std::hex << val
                     << std::endl;
        }
        mem_file.close();

        std::cout << "finished dumping memory" << std::endl;

    } catch (std::ofstream::failure &e) {
        std::cerr << "exception opening/reading/closing file memory_dump.bin\n";
    }
}
