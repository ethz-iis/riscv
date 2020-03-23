//`define SYNTHESIS

+incdir+${DESIGN_RTL_DIR}/include

${DESIGN_RTL_DIR}/include/apu_core_package.sv
${DESIGN_RTL_DIR}/fpnew/src/fpnew_pkg.sv
${DESIGN_RTL_DIR}/include/riscv_defines.sv
${DESIGN_RTL_DIR}/include/riscv_tracer_defines.sv
${DESIGN_RTL_DIR}/riscv_if_stage.sv
${DESIGN_RTL_DIR}/riscv_cs_registers.sv
${DESIGN_RTL_DIR}/riscv_register_file.sv
${DESIGN_RTL_DIR}/riscv_load_store_unit.sv
${DESIGN_RTL_DIR}/riscv_id_stage.sv
${DESIGN_RTL_DIR}/riscv_decoder.sv
${DESIGN_RTL_DIR}/riscv_compressed_decoder.sv
${DESIGN_RTL_DIR}/riscv_fetch_fifo.sv
${DESIGN_RTL_DIR}/riscv_prefetch_buffer.sv
${DESIGN_RTL_DIR}/riscv_prefetch_L0_buffer.sv
${DESIGN_RTL_DIR}/riscv_L0_buffer.sv
${DESIGN_RTL_DIR}/riscv_hwloop_regs.sv
${DESIGN_RTL_DIR}/riscv_hwloop_controller.sv
${DESIGN_RTL_DIR}/riscv_mult.sv
${DESIGN_RTL_DIR}/register_file_test_wrap.sv
${DESIGN_RTL_DIR}/riscv_int_controller.sv
${DESIGN_RTL_DIR}/riscv_ex_stage.sv
${DESIGN_RTL_DIR}/riscv_alu_div.sv
${DESIGN_RTL_DIR}/riscv_alu.sv

${DESIGN_RTL_DIR}/riscv_pmp.sv
${DESIGN_RTL_DIR}/riscv_apu_disp.sv
${DESIGN_RTL_DIR}/riscv_controller.sv

${DESIGN_RTL_DIR}/riscv_core.sv
 
