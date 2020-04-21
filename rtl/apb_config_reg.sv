module apb_config_reg
  (
   input wire        PRESETn,
   input wire        PCLK,
   input wire        PSEL,
   input wire        PENABLE,
   input wire [31:0] PADDR,
   input wire        PWRITE,
   input wire [31:0] PWDATA,
   output reg [31:0] PRDATA,
   output wire        PREADY,
   output reg        PSLVERR,

   output reg [31:0] config_reg0,
   output reg [31:0] config_reg1
   );


   reg               rready;
   

   //READ
   always @(posedge PCLK)
     case(PADDR) 
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
          case(PADDR) 
            0: config_reg0 <= PWDATA;
            1: config_reg1 <= PWDATA;
          endcase // case (PADDR)
     end // else: !if(~PRESETn)

            
endmodule
        
