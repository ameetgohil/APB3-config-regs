# APB3-config-regs
Implements two config registers with APB3 interface. Verification simulation done verilator using signalflip-js

## Dependencies
- [Verilator (version 4.0 or above)](https://www.veripool.org/projects/verilator/wiki/Installing)
- [nvm](https://github.com/creationix/nvm)
- cmake
- gtkwave (optional)

## To run simulation
```
cd sim
nvm use || nvm install
npm i
make

gtkwave logs/apb_read_write.fst
gtkwave logs/apb_write.fst
gtkwave logs/apb_read.fst
gtkwave logs/apb_read_write_simple.fst
```

### Simulation Reference
- [signalflip-js] (https://github.com/ameetgohil/signalflip-js)
- [Counter example] (https://github.com/ameetgohil/basic-signalflip-example)
- [Elastic Valid-Ready example] (https://github.com/ameetgohil/elastic-signalflip-example)
