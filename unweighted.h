#ifndef UNWEIGHTED_H
#define UNWEIGHTED_H


/*
 *  unweighted.h
 *  Mothur
 *
 *  Created by Sarah Westcott on 2/9/09.
 *  Copyright 2009 Schloss Lab UMASS Amherst. All rights reserved.
 *
 */

#include "treecalculator.h"
#include "treemap.h"

/***********************************************************************/

class Unweighted : public TreeCalculator  {
	
	public:
		Unweighted(TreeMap* t) : tmap(t) {};
		~Unweighted() {};
		EstOutput getValues(Tree*);
		
	private:
		GlobalData* globaldata;
		EstOutput data;
		vector<int> penalty;
		TreeMap* tmap;
		bool inUsersGroups(string);

};

/***********************************************************************/



#endif