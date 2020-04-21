module apb_config_reg
  (input wire PRESETn
   input wire PCLK,
   input wire PSEL,
   input wire PENABLE,
   input wire [31:0] PADDR,
   input wire PWRITE,
   input wire [31:0] PWDATA,
   output reg [31:0] PRDATA,
   output reg PREADY,
   output reg PSLVERR

   output reg [31:0] config_reg0
   output reg [31:0] config_reg1
   );



   //READ
   always @(posedge PCLK)
     case(PADDR) begin
        0: PRDATA <= config_reg0;
        1: PRDATA <= config_reg1;
        default: PRDATA <= 32'hDEADBEEF;
     endcase // case (PADDR)

   
   always @(posedge PCLK or negedge PRESETn)
     if(~PRESETn) begin
        PREADY <= 1'b0;
        PSLVERR <= 1'b0;
        config_reg0 <= 0;
        config_reg1 <= 0;
     end
     else begin
        PREADY <= 1'b1;
        PSLVERR <= 1'b0;
        if(PSEL & PENABLE & PWRITE)
          case(PADDR)
            0: config_reg0 <= PWDATA;
            1: config_reg1 <= PWDATA;
          endcase // case (PADDR)
     end // else: !if(~PRESETn)
endmodule
        
