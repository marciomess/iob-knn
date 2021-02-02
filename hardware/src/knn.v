`timescale 1ns/1ps
`include "iob_lib.vh"

module knn_core
  #(
    parameter DATA_W = 32
    )
   (
    `INPUT(en, 1),    
    `INPUT(clk, 1),
    `INPUT(rst, 1),
    `INPUT(x,32),
    `OUTPUT(y,32)
    );

   `SIGNAL(val, 32)
   `SIGNAL(reg_out_2, 32)
   `SIGNAL(reg_out_3, 32)
   `SIGNAL(reg_out_4, 32)

   //`REG_RE(clk, rst, 0, en, reg_out_1, x)
   `REG_RE(clk, rst, 0, en, reg_out_2, x)
   `REG_RE(clk, rst, 0, en, reg_out_3, reg_out_2)
   `REG_RE(clk, rst, 0, en, reg_out_4, reg_out_3)

   `COMB begin
      
      val = x * reg_out_2 - reg_out_3 / reg_out_4;

   end

   `SIGNAL2OUT(y, val)
      
endmodule

