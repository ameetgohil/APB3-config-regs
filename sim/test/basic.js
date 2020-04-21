const dut = require('../build/Release/dut.node');
const {Sim, SimUtils, RisingEdge, RisingEdges, FallingEdge, FallingEdges, Edge, Edges, Interfaces} = require('signalflip-js');
const { Clock } = SimUtils;
const {Elastic} = Interfaces;
const _ = require('lodash');
const APB3 = require('../APB3/APB3');

const jsc = require('jsverify');
const assert = require('assert');

let sim;
let apb3_master;

let write = (addr, data) => {
    apb3_master.dTxnArray.push({addr: addr, wdata: data, type: 'WRITE'});
};
let read = (addr) => {
    apb3_master.dTxnArray.push({addr: addr, type: 'READ'});
};

describe('Basic Group', () => {
    let setup = (name) => {
	// set up the environment
	dut.init(name); // Init dut
	sim = new Sim(dut);
	
	// TODO: Create clock
	let clk = new Clock(dut.PCLK, 1);
	sim.addClock(clk);
	
	// TODO: Add setup code (interfaces, transaction, ...) etc...
	apb3_master = new APB3(sim, dut.PCLK, dut.PRESETn, dut.PSEL, dut.PENABLE, dut.PADDR, dut.PWRITE, dut.PWDATA, dut.PRDATA, dut.PREADY, dut.PSLVERR);

	apb3_master.init();


	//Helper function for pushing read/write txn
	

	
	// TODO: Add reset task
	// sim.addTask(function* () {
	//   dut.rstf(0);
	//   yield* RisingEdges(dut.clk, 10); // assert reset low for 10 clock cycles
	//   dut.rstf(1);
	//   yield* RisingEdge(dut.clk);
	// }(), 'RESET');
	
	// TODO: Add post_run tasks (test checking)
	// sim.addTask(() => { /* post_run function */}, 'POST_RUN'});
	sim.addTask(() => { console.log(apb3_master.mTxnArray); }, 'POST_RUN');
    };
    it('APB READ-WRITE', function () {
	this.timeout(10000); // Set timeout to expected run time of the test in ms
	setup('apb_read_write');
	// TODO: customize txn, randomizer, set variables/signals
	write(0,0xA5A5A5A5);
	write(1,0x1234AAAA);
	write(0,0xDEADDEAD);
	write(1,0xCAFEBABE);
	read(0);
	read(1);
	write(0,0xABCDCAFE);
	sim.run(1000); //run for 1000 ticks
    });

    it('APB WRITE', function () {
	this.timeout(10000); // Set timeout to expected run time of the test in ms
	setup('apb_write');
	write(0,1);
	write(0,2);
	write(0,3);
	write(1,0xAA);
	write(0,0x12345678);
	write(1,0xCAFEBABE);
	sim.run(1000);
    });

    it('APB READ', function () {
	this.timeout(10000); // Set timeout to expected run time of the test in ms
	setup('apb_read');
	write(0,0x12345678);
	write(1,0xCAFEBABE);
	read(0);
	read(1);
	write(0,0xAAAABBBB);
	read(0);
	write(1,0x5555CCCC);
	read(1);
	sim.run(1000);
    });

    it('APB READ-WRITE SIMPLE', function () {
	this.timeout(10000); // Set timeout to expected run time of the test in ms
	setup('apb_read_write_simple');
	write(0,1);
	write(1,2);
	write(0,3);
	write(1,4);
	read(0);
	read(1);
	write(0,5);
	read(0);
	read(1);
	sim.run(1000);
	
    });
});

