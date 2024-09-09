`timescale 1ps / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/09/01 22:49:35
// Design Name: 
// Module Name: Flash_led_top_tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module flash_led_top_tb;
 	 	reg clk,rst,sw0;
 	 	wire [15:0] led;
 	  	initial begin
 	 		clk = 1'b0;
 	 		rst = 1'b1;
 	 		sw0 = 1'b0;
 	 		#10 rst = 1'b0;
 	 		#10 rst = 1'b1;
 	 		#1000000000				 //6ms后改变位移方向
 	 		#1000000000
 	 		#1000000000
 	 		#1000000000
 	 		#1000000000
 	 		#1000000000
 	 		sw0 = 1'b1;
 	 	end
 	 	always #5 clk <= ~clk;
 	 	flash_led_top flash_led_top(
 	 		.clk( clk ),
 	 		.rst_n( rst ),
 	 		.sw0( sw0 ),
 	 		.led( led )
 	 	);
endmodule
