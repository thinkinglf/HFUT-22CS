`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/08/29 17:25:19
// Design Name: 
// Module Name: flash_led_top
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


module flash_led_top(
        input clk,
 	 	input rst_n,
 	 	input sw0,
 	 	output [15:0]led
 	 	);
 	 	wire clk_bps;
 	 	wire rst;
 	 	assign rst = ~rst_n;
 	 	
 	 	counter counter(
 	 		.clk( clk ),
 	 		.rst( rst ),
 	 		.clk_bps( clk_bps )
 	 	);
 	 	flash_led_ctl flash_led_ctl(
 	 		.clk( clk ),
 	 		.rst( rst ),
 	 		.dir( sw0 ),
 	 		.clk_bps( clk_bps ),
 	 		.led( led )
 	 	);
endmodule
