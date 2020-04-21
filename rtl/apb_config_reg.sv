module apb_config_reg
  (
   input wire        PRESETn,
   input wire        PCLK,
   input wire        PSEL,
   input wire        PENABLE,
   // PADDR bits 1:0 unused b/c of byte addressing
   /* verilator lint_off UNUSED */
   input wire [31:0] PADDR,
   /* verilator lint_on UNUSED */
   input wire        PWRITE,
   input wire [31:0] PWDATA,
   output reg [31:0] PRDATA,
   output wire       PREADY,
   output reg        PSLVERR,

   output reg [31:0] config_reg0,
   output reg [31:0] config_reg1
   );


   reg               rready;
   

   //READ
   always @(posedge PCLK)
     case(PADDR[31:2]) 
        0: PRDATA <= config_reg0;
        1: PRDATA <= config_reg1;
        default: PRDATA <= 32'hDEADBEEF;
     endcase // case (PADDR)


   assign PREADY = PWRITE ? 1'b1:rready;
   
   always @(posedge PCLK or negedge PRESETn) begin
      if(~PRESETn) begin
         rready <= 0;
      end
      else begin
         rready <= 0;
         if(~PWRITE & PENABLE & PSEL & ~rready)
           rready <= 1;
      end
   end
         
            
            
   always @(posedge PCLK or negedge PRESETn)
     if(~PRESETn) begin
        PSLVERR <= 1'b0;
        config_reg0 <= 0;
        config_reg1 <= 0;
     end
     else begin
        PSLVERR <= 1'b0;
        if(PSEL & PENABLE & PWRITE)
          case(PADDR[31:2]) 
            0: config_reg0 <= PWDATA;
            1: config_reg1 <= PWDATA;
          endcase // case (PADDR)
     end // else: !if(~PRESETn)

            
endmodule
        
