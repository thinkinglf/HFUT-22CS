`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2016/08/29 17:23:43
// Design Name: 
// Module Name: flash_led_ctl
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


module flash_led_ctl(
 	 	input clk,
 	 	input rst,
 	 	input dir,
 	 	input clk_bps,
 	 	output reg[15:0]led
 	 	);
 	 	always @( posedge clk or posedge rst )
 	 		if( rst )
 	 			led <= 16'h8000;
 	 		else
 	 			case( dir )
 	 				1'b0:  			 //从左向右
 	 					if( clk_bps )
 	 				 		if( led != 16'd1 )
 	 							led <= led >> 1'b1;
 	 						else
 	 							led <= 16'h8000;
 	 				1'b1:  			 //从右向左
 	 			 		if( clk_bps )
 	 						if( led != 16'h8000 )
 	 							led <= led << 1'b1;
 	 						else
 	 							led <= 16'd1;
 	 			endcase
endmodule

