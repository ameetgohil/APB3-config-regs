#include "signals.h"
#include <verilated.h>
#include <sys/stat.h>
#include <string>

// Include model header, generated from Verilating "top.v"
#include "Vapb_config_reg.h"

// If "verilator --trace" is used, include the tracing class
//#if VM_TRACE

#include <verilated_fst_c.h>
VerilatedFstC* tfp;

//#endif

// // Current simulation time (64-bit unsigned)
 vluint64_t main_time = 0;
// // Called by $time in Verilog
 double sc_time_stamp() {
     return 0;//main_time;  // Note does conversion to real, to match SystemC
 }
//

union WideSignal {
  uint32_t* sig32;
  uint64_t* sig64;
  };

const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
const std::unique_ptr<Vapb_config_reg> top{new Vapb_config_reg{contextp.get(), "TOP"}};
void signals::init_top(std::string name) {

  //Verilated::debug(0);
  // Set debug level, 0 is off, 9 is highest presently used
  Verilated::debug(0);
  // Randomization reset policy
  Verilated::randReset(2);

  // Construct the Verilated model, from Vtop.h generated from Verilating "top.v"
  //const std::unique_ptr<Vapb_config_reg> xtop{new Vapb_config_reg{contextp.get(), "apb_config_reg"}};
  //top = xtop;

  //#if VM_TRACE
  // If verilator was invoked with --trace argument,
  // and if at run time passed the +trace argument, turn on tracing
  tfp = NULL;
  //  const char* flag = Verilated::commandArgsPlusMatch("trace");
  //  if (flag && 0==strcmp(flag, "+trace")) {
    Verilated::traceEverOn(true);  // Verilator must compute traced signals
    //VL_PRINTF("Enabling waves into logs/vlt_dump.vcd...\n");

    tfp = new VerilatedFstC;

    top->trace(tfp, 99);  // Trace 99 levels of hierarchy
    Verilated::mkdir("logs");

    //mkdir("logs",0x775);

	std::string f = "logs/" + name + ".fst";

       tfp->open(f.c_str());

    //  }
  //#endif

  // Set some inputs
}

  
      
	
uint32_t signals::PRESETn(uint32_t val) {
  top->PRESETn = val;
  return top->PRESETn;
}
	
      
  
      
	
uint32_t signals::PCLK(uint32_t val) {
  top->PCLK = val;
  return top->PCLK;
}
	
      
  
      
	
uint32_t signals::PSEL(uint32_t val) {
  top->PSEL = val;
  return top->PSEL;
}
	
      
  
      
	
uint32_t signals::PENABLE(uint32_t val) {
  top->PENABLE = val;
  return top->PENABLE;
}
	
      
  
      
	
uint32_t signals::PWRITE(uint32_t val) {
  top->PWRITE = val;
  return top->PWRITE;
}
	
      
  
      
	
uint32_t signals::PREADY() {
  return top->PREADY;
}
	
      
  
      
	
uint32_t signals::PSLVERR() {
  return top->PSLVERR;
}
	
      
  
      
	
uint32_t signals::PADDR(uint32_t val) {
  top->PADDR = val;
  return top->PADDR;
}
	
      
  
      
	
uint32_t signals::PWDATA(uint32_t val) {
  top->PWDATA = val;
  return top->PWDATA;
}
	
      
  
      
	
uint32_t signals::PRDATA() {
  return top->PRDATA;
}
	
      
  
      
	
uint32_t signals::config_reg0() {
  return top->config_reg0;
}
	
      
  
      
	
uint32_t signals::config_reg1() {
  return top->config_reg1;
}
	
      
  


int signals::eval(uint64_t time) {
  contextp->timeInc(time-main_time);
  main_time = time;
  top->eval();
  tfp->dump(contextp->time());
  // Read outputs
  /*  VL_PRINTF ("[%" VL_PRI64 "d] clk=%x rstl=%x iquad=%" VL_PRI64 "x"
	     " -> oquad=%" VL_PRI64"x owide=%x_%08x_%08x\n",
	     main_time, top->clk, top->reset_l, top->in_quad,
	     top->out_quad, top->out_wide[2], top->out_wide[1], top->out_wide[0]);*/
  return 0;
}

int signals::finish() {
  top->final();
  tfp->close();
  tfp = NULL;
  return 0;
}


    
      
Napi::Number signals::PRESETnWrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if(info.Length() > 1 || (info.Length() == 1 && !info[0].IsNumber())) {
    Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
  }
    
  Napi::Number returnValue;
  if(info.Length() == 1) {
    Napi::Number val = info[0].As<Napi::Number>();
    returnValue = Napi::Number::New(env, signals::PRESETn(val.Int32Value()));
  } else {
    returnValue = Napi::Number::New(env, top->PRESETn);
  }
  return returnValue;
}
      
    

    
      
Napi::Number signals::PCLKWrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if(info.Length() > 1 || (info.Length() == 1 && !info[0].IsNumber())) {
    Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
  }
    
  Napi::Number returnValue;
  if(info.Length() == 1) {
    Napi::Number val = info[0].As<Napi::Number>();
    returnValue = Napi::Number::New(env, signals::PCLK(val.Int32Value()));
  } else {
    returnValue = Napi::Number::New(env, top->PCLK);
  }
  return returnValue;
}
      
    

    
      
Napi::Number signals::PSELWrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if(info.Length() > 1 || (info.Length() == 1 && !info[0].IsNumber())) {
    Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
  }
    
  Napi::Number returnValue;
  if(info.Length() == 1) {
    Napi::Number val = info[0].As<Napi::Number>();
    returnValue = Napi::Number::New(env, signals::PSEL(val.Int32Value()));
  } else {
    returnValue = Napi::Number::New(env, top->PSEL);
  }
  return returnValue;
}
      
    

    
      
Napi::Number signals::PENABLEWrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if(info.Length() > 1 || (info.Length() == 1 && !info[0].IsNumber())) {
    Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
  }
    
  Napi::Number returnValue;
  if(info.Length() == 1) {
    Napi::Number val = info[0].As<Napi::Number>();
    returnValue = Napi::Number::New(env, signals::PENABLE(val.Int32Value()));
  } else {
    returnValue = Napi::Number::New(env, top->PENABLE);
  }
  return returnValue;
}
      
    

    
      
Napi::Number signals::PWRITEWrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if(info.Length() > 1 || (info.Length() == 1 && !info[0].IsNumber())) {
    Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
  }
    
  Napi::Number returnValue;
  if(info.Length() == 1) {
    Napi::Number val = info[0].As<Napi::Number>();
    returnValue = Napi::Number::New(env, signals::PWRITE(val.Int32Value()));
  } else {
    returnValue = Napi::Number::New(env, top->PWRITE);
  }
  return returnValue;
}
      
    

    
      
Napi::Number signals::PREADYWrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if(info.Length() > 0) {
    Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
  }
    
  Napi::Number returnValue;
  returnValue = Napi::Number::New(env, top->PREADY);
  return returnValue;
}
      
    

    
      
Napi::Number signals::PSLVERRWrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if(info.Length() > 0) {
    Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
  }
    
  Napi::Number returnValue;
  returnValue = Napi::Number::New(env, top->PSLVERR);
  return returnValue;
}
      
    

    
      
Napi::Number signals::PADDRWrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if(info.Length() > 1 || (info.Length() == 1 && !info[0].IsNumber())) {
    Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
  }
    
  Napi::Number returnValue;
  if(info.Length() == 1) {
    Napi::Number val = info[0].As<Napi::Number>();
    returnValue = Napi::Number::New(env, signals::PADDR(val.Int32Value()));
  } else {
    returnValue = Napi::Number::New(env, top->PADDR);
  }
  return returnValue;
}
      
    

    
      
Napi::Number signals::PWDATAWrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if(info.Length() > 1 || (info.Length() == 1 && !info[0].IsNumber())) {
    Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
  }
    
  Napi::Number returnValue;
  if(info.Length() == 1) {
    Napi::Number val = info[0].As<Napi::Number>();
    returnValue = Napi::Number::New(env, signals::PWDATA(val.Int32Value()));
  } else {
    returnValue = Napi::Number::New(env, top->PWDATA);
  }
  return returnValue;
}
      
    

    
      
Napi::Number signals::PRDATAWrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if(info.Length() > 0) {
    Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
  }
    
  Napi::Number returnValue;
  returnValue = Napi::Number::New(env, top->PRDATA);
  return returnValue;
}
      
    

    
      
Napi::Number signals::config_reg0Wrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if(info.Length() > 0) {
    Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
  }
    
  Napi::Number returnValue;
  returnValue = Napi::Number::New(env, top->config_reg0);
  return returnValue;
}
      
    

    
      
Napi::Number signals::config_reg1Wrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if(info.Length() > 0) {
    Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
  }
    
  Napi::Number returnValue;
  returnValue = Napi::Number::New(env, top->config_reg1);
  return returnValue;
}
      
    




void signals::evalWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if(info.Length() > 1 || (info.Length() == 1 && !info[0].IsNumber())) {
	Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    }
    Napi::Number val = info[0].As<Napi::Number>();
    signals::eval(val.Int64Value());
  // Napi::Env env = info.Env();

  // Napi::Number returnValue = Napi::Number::New(env, signals::eval());
  // return returnValue;
  
}

void signals::finishWrapped(const Napi::CallbackInfo& info) {
    signals::finish();
    // Napi::Env env = info.Env();

    // Napi::Number returnValue = Napi::Number::New(env, signals::finish());
    // return returnValue;
}

void signals::initWrapped(const Napi::CallbackInfo& info) {
    std::string name = "waveform";
    Napi::Env env = info.Env();
    if(info.Length() > 0 ) {
	if(!info[0].IsString()) {
	    Napi::TypeError::New(env, "String expected").ThrowAsJavaScriptException();
	}
	Napi::String val = info[0].As<Napi::String>();
	name = val.Utf8Value();
    }
    signals::init_top(name);
}

Napi::Object signals::Init(Napi::Env env, Napi::Object exports) {



  exports.Set("PRESETn", Napi::Function::New(env, signals::PRESETnWrapped));



  exports.Set("PCLK", Napi::Function::New(env, signals::PCLKWrapped));



  exports.Set("PSEL", Napi::Function::New(env, signals::PSELWrapped));



  exports.Set("PENABLE", Napi::Function::New(env, signals::PENABLEWrapped));



  exports.Set("PWRITE", Napi::Function::New(env, signals::PWRITEWrapped));



  exports.Set("PREADY", Napi::Function::New(env, signals::PREADYWrapped));



  exports.Set("PSLVERR", Napi::Function::New(env, signals::PSLVERRWrapped));



  exports.Set("PADDR", Napi::Function::New(env, signals::PADDRWrapped));



  exports.Set("PWDATA", Napi::Function::New(env, signals::PWDATAWrapped));



  exports.Set("PRDATA", Napi::Function::New(env, signals::PRDATAWrapped));



  exports.Set("config_reg0", Napi::Function::New(env, signals::config_reg0Wrapped));



  exports.Set("config_reg1", Napi::Function::New(env, signals::config_reg1Wrapped));


  exports.Set("eval", Napi::Function::New(env, signals::evalWrapped));
  exports.Set("finish", Napi::Function::New(env, signals::finishWrapped));
  exports.Set("init", Napi::Function::New(env, signals::initWrapped));
  return exports;

}
