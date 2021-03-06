#ifndef CHIMERACCODECOMMAND_H
#define CHIMERACCODECOMMAND_H

/*
 *  chimeraccodecommand.h
 *  Mothur
 *
 *  Created by westcott on 3/30/10.
 *  Copyright 2010 Schloss Lab. All rights reserved.
 *
 */

#include "mothur.h"
#include "command.hpp"
#include "mothurchimera.h"


/***********************************************************/

class ChimeraCcodeCommand : public Command {
public:
	ChimeraCcodeCommand(string);
	ChimeraCcodeCommand();
	~ChimeraCcodeCommand(){}
	
	vector<string> setParameters();
	string getCommandName()			{ return "chimera.ccode";		}
	string getCommandCategory()		{ return "Sequence Processing"; }
	
	string getHelpString();	
    string getOutputPattern(string);	
	string getCitation() { return "Gonzalez JM, Zimmermann J, Saiz-Jimenez C (2005). Evaluating putative chimeric sequences from PCR-amplified products. Bioinformatics 21: 333-7. \nhttp://www.mothur.org/wiki/Chimera.ccode"; }
	string getDescription()		{ return "detect chimeric sequences"; }
	
	int execute(); 
	void help() { m->mothurOut(getHelpString()); }	
	
		
private:
	int driver(string, string, string);
	bool abort, filter, save;
	string fastafile, templatefile, outputDir, maskfile;
	int window, numwanted, numSeqs, templateSeqsLength;
	MothurChimera* chimera;
	vector<string> fastaFileNames;
	vector<string> outputNames;
};

/***********************************************************/

#endif

