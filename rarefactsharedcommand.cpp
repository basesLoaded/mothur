/*
 *  rarefactsharedcommand.cpp
 *  Dotur
 *
 *  Created by Sarah Westcott on 1/6/09.
 *  Copyright 2009 Schloss Lab UMASS Amherst. All rights reserved.
 *
 */

#include "rarefactsharedcommand.h"
#include "sharedsobs.h"

//**********************************************************************************************************************

RareFactSharedCommand::RareFactSharedCommand(){
	try {
		globaldata = GlobalData::getInstance();
		string fileNameRoot;
		fileNameRoot = getRootName(globaldata->inputFileName);
				
		int i;
		for (i=0; i<globaldata->sharedRareEstimators.size(); i++) {
			if (globaldata->sharedRareEstimators[i] == "sharedobserved") { 
				rDisplays.push_back(new RareDisplay(new SharedSobs(), new SharedThreeColumnFile(fileNameRoot+"shared.rarefaction", "")));
			}
		}
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the RareFactSharedCommand class Function RareFactSharedCommand. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the RareFactSharedCommand class function RareFactSharedCommand. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
			
}

//**********************************************************************************************************************

RareFactSharedCommand::~RareFactSharedCommand(){
	delete order;
	delete input;
	delete rCurve;
	delete read;
}

//**********************************************************************************************************************

int RareFactSharedCommand::execute(){
	try {
		int count = 1;
		read = new ReadPhilFile(globaldata->inputFileName);	
		read->read(&*globaldata); 
		
		input = globaldata->ginput;
		SharedList = globaldata->gSharedList;
		order = SharedList->getSharedOrderVector();
		
		while(order != NULL){
		
			if(globaldata->allLines == 1 || globaldata->lines.count(count) == 1 || globaldata->labels.count(order->getLabel()) == 1){
				//create collectors curve
				rCurve = new Rarefact(order, rDisplays);
				convert(globaldata->getFreq(), freq);
				convert(globaldata->getIters(), nIters);
				rCurve->getSharedCurve(freq, nIters);
			
				delete rCurve;
			
				cout << order->getLabel() << '\t' << count << endl;
			}
			
			SharedList = input->getSharedListVector(); //get new list vector to process
			if (SharedList != NULL) {
				order = SharedList->getSharedOrderVector(); //gets new order vector with group info.
				count++;
			}else {
				break;
			}
		
		}
	
		for(int i=0;i<rDisplays.size();i++){	delete rDisplays[i];	}	
		return 0;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the RareFactSharedCommand class Function execute. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the RareFactSharedCommand class function execute. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}


//**********************************************************************************************************************
