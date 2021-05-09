#include "napi.h"
#include <string>

namespace signals {

    void init_top(std::string name);
  
  int tick();
  
      
	
  uint32_t PRESETn(uint32_t val);
	
      
  
      
	
  uint32_t PCLK(uint32_t val);
	
      
  
      
	
  uint32_t PSEL(uint32_t val);
	
      
  
      
	
  uint32_t PENABLE(uint32_t val);
	
      
  
      
	
  uint32_t PWRITE(uint32_t val);
	
      
  
      
	
  uint32_t PREADY();
	
      
  
      
	
  uint32_t PSLVERR();
	
      
  
      
	
  uint32_t PADDR(uint32_t val);
	
      
  
      
	
  uint32_t PWDATA(uint32_t val);
	
      
  
      
	
  uint32_t PRDATA();
	
      
  
      
	
  uint32_t config_reg0();
	
      
  
      
	
  uint32_t config_reg1();
	
      
  
  int eval(uint64_t time);
  int finish();
  
  Napi::Number TickWrapped(const Napi::CallbackInfo& info);
  
      
  Napi::Number PRESETnWrapped(const Napi::CallbackInfo& info);
      
  
      
  Napi::Number PCLKWrapped(const Napi::CallbackInfo& info);
      
  
      
  Napi::Number PSELWrapped(const Napi::CallbackInfo& info);
      
  
      
  Napi::Number PENABLEWrapped(const Napi::CallbackInfo& info);
      
  
      
  Napi::Number PWRITEWrapped(const Napi::CallbackInfo& info);
      
  
      
  Napi::Number PREADYWrapped(const Napi::CallbackInfo& info);
      
  
      
  Napi::Number PSLVERRWrapped(const Napi::CallbackInfo& info);
      
  
      
  Napi::Number PADDRWrapped(const Napi::CallbackInfo& info);
      
  
      
  Napi::Number PWDATAWrapped(const Napi::CallbackInfo& info);
      
  
      
  Napi::Number PRDATAWrapped(const Napi::CallbackInfo& info);
      
  
      
  Napi::Number config_reg0Wrapped(const Napi::CallbackInfo& info);
      
  
      
  Napi::Number config_reg1Wrapped(const Napi::CallbackInfo& info);
      
  
  void evalWrapped(const Napi::CallbackInfo& info);
  void finishWrapped(const Napi::CallbackInfo& info);
  void initWrapped(const Napi::CallbackInfo& info);
  Napi::Object Init(Napi::Env env, Napi::Object exports);
};

