#ifndef PROTO_H
#define PROTO_H

#include "types.h"

// Macros **********************************************************************

// Console
extern Console console;
#define log(msg) { console._log(msg); }

// Functions *******************************************************************

// System
void sys_start();
void sys_exit();
std::string state_name(const state_t& name);

// Input
int get_ch(WINDOW* wnd);
void process_input(int keycode);

// Input Map
void read_inputmap();

// Text
void print_msg(const message_t& msg);
std::vector<int> vec_fmt(const std::string& str, int fmt_flags = 0);
std::list<std::vector<int> > word_fmt(const std::string& str, int fmt_flags = 0);
std::string vec_str(std::vector<int> word);

#endif