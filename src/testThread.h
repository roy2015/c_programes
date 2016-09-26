/*
 * testThread.h
 *
 *  Created on: 2016年9月23日
 *      Author: apple
 */

#ifndef TESTTHREAD_H_
#include<glib.h>
#include<glib/gtypes.h>
#define TESTTHREAD_H_
#endif /* TESTTHREAD_H_ */

struct Cust_Message {
	gint id;
	gpointer user_message;
};

void show_result(gpointer str, gpointer data);
void testThread();
