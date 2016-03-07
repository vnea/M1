/* sscc : C CODE OF SORTED EQUATIONS GERANT - SIMULATION MODE */

/* AUXILIARY DECLARATIONS */

#ifndef STRLEN
#define STRLEN 81
#endif
#define _COND(A,B,C) ((A)?(B):(C))
#ifdef TRACE_ACTION
#include <stdio.h>
#endif
#ifndef NULL
#define NULL ((char*)0)
#endif

#ifndef __EXEC_STATUS_H_LOADED
#define __EXEC_STATUS_H_LOADED

typedef struct {
unsigned int start:1;
unsigned int kill:1;
unsigned int active:1;
unsigned int suspended:1;
unsigned int prev_active:1;
unsigned int prev_suspended:1;
unsigned int exec_index;
unsigned int task_exec_index;
void (*pStart)();
void (*pRet)();
} __ExecStatus;

#endif
#define __ResetExecStatus(status) {\
   status.prev_active = status.active; \
   status.prev_suspended = status.suspended; \
   status.start = status.kill = status.active = status.suspended = 0; }
#define __DSZ(V) (--(V)<=0)
#define BASIC_TYPES_DEFINED
typedef int boolean;
typedef int integer;
typedef char* string;
#define CSIMUL_H_LOADED
typedef struct {char text[STRLEN];} symbolic;
extern void _boolean(boolean*, boolean);
extern boolean _eq_boolean(boolean, boolean);
extern boolean _ne_boolean(boolean, boolean);
extern boolean _cond_boolean(boolean ,boolean ,boolean);
extern char* _boolean_to_text(boolean);
extern int _check_boolean(char*);
extern void _text_to_boolean(boolean*, char*);
extern void _integer(integer*, integer);
extern boolean _eq_integer(integer, integer);
extern boolean _ne_integer(integer, integer);
extern integer _cond_integer(boolean ,integer ,integer);
extern char* _integer_to_text(integer);
extern int _check_integer(char*);
extern void _text_to_integer(integer*, char*);
extern void _string(string, string);
extern boolean _eq_string(string, string);
extern boolean _ne_string(string, string);
extern string _cond_string(boolean ,string ,string);
extern char* _string_to_text(string);
extern int _check_string(char*);
extern void _text_to_string(string, char*);
extern void _float(float*, float);
extern boolean _eq_float(float, float);
extern boolean _ne_float(float, float);
extern float _cond_float(boolean ,float ,float);
extern char* _float_to_text(float);
extern int _check_float(char*);
extern void _text_to_float(float*, char*);
extern void _double(double*, double);
extern boolean _eq_double(double, double);
extern boolean _ne_double(double, double);
extern double _cond_double(boolean ,double ,double);
extern char* _double_to_text(double);
extern int _check_double(char*);
extern void _text_to_double(double*, char*);
extern void _symbolic(symbolic*, symbolic);
extern boolean _eq_symbolic(symbolic, symbolic);
extern boolean _ne_symbolic(symbolic, symbolic);
extern symbolic _cond_symbolic(boolean ,symbolic ,symbolic);
extern char* _symbolic_to_text(symbolic);
extern int _check_symbolic(char*);
extern void _text_to_symbolic(symbolic*, char*);
extern char* __PredefinedTypeToText(int, char*);
#define _true 1
#define _false 0
#define __GERANT_GENERIC_TEST(TEST) return TEST;
typedef void (*__GERANT_APF)();
static __GERANT_APF *__GERANT_PActionArray;
static int **__GERANT_PCheckArray;
struct __SourcePoint {
int linkback;
int line;
int column;
int instance_index;
};
struct __InstanceEntry {
char *module_name;
int father_index;
char *dir_name;
char *file_name;
struct __SourcePoint source_point;
struct __SourcePoint end_point;
struct __SourcePoint instance_point;
};
struct __TaskEntry {
char *name;
int   nb_args_ref;
int   nb_args_val;
int  *type_codes_array;
struct __SourcePoint source_point;
};
struct __SignalEntry {
char *name;
int code;
int variable_index;
int present;
struct __SourcePoint source_point;
int number_of_emit_source_points;
struct __SourcePoint* emit_source_point_array;
int number_of_present_source_points;
struct __SourcePoint* present_source_point_array;
int number_of_access_source_points;
struct __SourcePoint* access_source_point_array;
};
struct __InputEntry {
char *name;
int hash;
char *type_name;
int is_a_sensor;
int type_code;
int multiple;
int signal_index;
int (*p_check_input)(char*);
void (*p_input_function)();
int present;
struct __SourcePoint source_point;
};
struct __ReturnEntry {
char *name;
int hash;
char *type_name;
int type_code;
int signal_index;
int exec_index;
int (*p_check_input)(char*);
void (*p_input_function)();
int present;
struct __SourcePoint source_point;
};
struct __ImplicationEntry {
int master;
int slave;
struct __SourcePoint source_point;
};
struct __ExclusionEntry {
int *exclusion_list;
struct __SourcePoint source_point;
};
struct __VariableEntry {
char *full_name;
char *short_name;
char *type_name;
int type_code;
int comment_kind;
int is_initialized;
char *p_variable;
char *source_name;
int written;
unsigned char written_in_transition;
unsigned char read_in_transition;
struct __SourcePoint source_point;
};
struct __ExecEntry {
int task_index;
int *var_indexes_array;
char **p_values_array;
struct __SourcePoint source_point;
};
struct __HaltEntry {
struct __SourcePoint source_point;
};
struct __NetEntry {
int known;
int value;
int number_of_source_points;
struct __SourcePoint* source_point_array;
};
struct __ModuleEntry {
char *version_id;
char *name;
int number_of_instances;
int number_of_tasks;
int number_of_signals;
int number_of_inputs;
int number_of_returns;
int number_of_sensors;
int number_of_outputs;
int number_of_locals;
int number_of_exceptions;
int number_of_implications;
int number_of_exclusions;
int number_of_variables;
int number_of_execs;
int number_of_halts;
int number_of_nets;
int number_of_states;
int state;
unsigned short *halt_list;
unsigned short *awaited_list;
unsigned short *emitted_list;
unsigned short *started_list;
unsigned short *killed_list;
unsigned short *suspended_list;
unsigned short *active_list;
int run_time_error_code;
int error_info;
void (*init)();
int (*run)();
int (*reset)();
char *(*show_variable)(int);
void (*set_variable)(int, char*, char*);
int (*check_value)(int, char*);
int (*execute_action)();
struct __InstanceEntry* instance_table;
struct __TaskEntry* task_table;
struct __SignalEntry* signal_table;
struct __InputEntry* input_table;
struct __ReturnEntry* return_table;
struct __ImplicationEntry* implication_table;
struct __ExclusionEntry* exclusion_table;
struct __VariableEntry* variable_table;
struct __ExecEntry* exec_table;
struct __HaltEntry* halt_table;
struct __NetEntry* net_table;
};

#include "gerant.h"

/* EXTERN DECLARATIONS */

extern int __CheckVariables(int*);
extern void __ResetInput();
extern void __ResetExecs();
extern void __ResetVariables();
extern void __ResetVariableStatus();
extern void __AppendToList(unsigned short*, unsigned short);
extern void __ListCopy(unsigned short*, unsigned short**);
extern void __WriteVariable(int);
extern void __ResetVariable(int);
extern void __ResetModuleEntry();
extern void __ResetModuleEntryBeforeReaction();
extern void __ResetModuleEntryAfterReaction();
#ifndef _NO_EXTERN_DEFINITIONS
#ifndef _NO_CONSTANT_DEFINITIONS
#ifndef _max_DEFINED
#ifndef max
extern integer max;
#endif
#endif
#endif
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static boolean __GERANT_V0;
static integer __GERANT_V1;
static boolean __GERANT_V2;
static integer __GERANT_V3;
static integer __GERANT_V4;
static integer __GERANT_V5;

static unsigned short __GERANT_HaltList[2];
static unsigned short __GERANT_AwaitedList[10];
static unsigned short __GERANT_EmittedList[10];
static unsigned short __GERANT_StartedList[1];
static unsigned short __GERANT_KilledList[1];
static unsigned short __GERANT_SuspendedList[1];
static unsigned short __GERANT_ActiveList[1];
static unsigned short __GERANT_AllAwaitedList[10]={2,0,1};


/* INPUT FUNCTIONS */

void GERANT_I_FIN () {
__GERANT_V0 = _true;
}
void GERANT_IS_FIN () {
__GERANT_V0 = _true;
}
void GERANT_I_C (integer __V) {
__WriteVariable(1);
__GERANT_V1 = __V;
__GERANT_V2 = _true;
}
void GERANT_IS_C (string __V) {
__WriteVariable(1);
_text_to_integer(&__GERANT_V1,__V);
__GERANT_V2 = _true;
}

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int GERANT_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

static int __GERANT_A1 () {
__GERANT_GENERIC_TEST(__GERANT_V0);
}
static int __GERANT_Check1 [] = {1,0,0};
static int __GERANT_A2 () {
__GERANT_GENERIC_TEST(__GERANT_V2);
}
static int __GERANT_Check2 [] = {1,0,0};

/* OUTPUT ACTIONS */

static void __GERANT_A3 () {
#ifdef __OUTPUT
GERANT_O_P();
#endif
__AppendToList(__GERANT_EmittedList,2);
}
static int __GERANT_Check3 [] = {1,0,0};
static void __GERANT_A4 () {
#ifdef __OUTPUT
GERANT_O_MAX();
#endif
__AppendToList(__GERANT_EmittedList,3);
}
static int __GERANT_Check4 [] = {1,0,0};
static void __GERANT_A5 () {
#ifdef __OUTPUT
GERANT_O_VIDE();
#endif
__AppendToList(__GERANT_EmittedList,4);
}
static int __GERANT_Check5 [] = {1,0,0};
static void __GERANT_A6 () {
#ifdef __OUTPUT
GERANT_O_C_S(__GERANT_V3);
#endif
__AppendToList(__GERANT_EmittedList,5);
}
static int __GERANT_Check6 [] = {1,0,0};
static void __GERANT_A7 () {
#ifdef __OUTPUT
GERANT_O_P_S();
#endif
__AppendToList(__GERANT_EmittedList,6);
}
static int __GERANT_Check7 [] = {1,0,0};
static void __GERANT_A8 () {
#ifdef __OUTPUT
GERANT_O_ST(__GERANT_V4);
#endif
__AppendToList(__GERANT_EmittedList,7);
}
static int __GERANT_Check8 [] = {1,0,0};
static void __GERANT_A9 () {
#ifdef __OUTPUT
GERANT_O_FS(__GERANT_V5);
#endif
__AppendToList(__GERANT_EmittedList,8);
}
static int __GERANT_Check9 [] = {1,0,0};

/* ASSIGNMENTS */

static void __GERANT_A10 () {
__GERANT_V0 = _false;
}
static int __GERANT_Check10 [] = {1,0,1,0};
static void __GERANT_A11 () {
__GERANT_V2 = _false;
}
static int __GERANT_Check11 [] = {1,0,1,2};

/* PROCEDURE CALLS */

/* CONDITIONS */

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

static void __GERANT_A12 () {
;
__ResetVariable(1);
}
static int __GERANT_Check12 [] = {1,0,0};
static void __GERANT_A13 () {
;
__ResetVariable(3);
}
static int __GERANT_Check13 [] = {1,0,0};
static void __GERANT_A14 () {
;
__ResetVariable(4);
}
static int __GERANT_Check14 [] = {1,0,0};
static void __GERANT_A15 () {
;
__ResetVariable(5);
}
static int __GERANT_Check15 [] = {1,0,0};

/* ACTION SEQUENCES */


static int *__GERANT_CheckArray[] = {
0,
__GERANT_Check1,
__GERANT_Check2,
__GERANT_Check3,
__GERANT_Check4,
__GERANT_Check5,
__GERANT_Check6,
__GERANT_Check7,
__GERANT_Check8,
__GERANT_Check9,
__GERANT_Check10,
__GERANT_Check11,
__GERANT_Check12,
__GERANT_Check13,
__GERANT_Check14,
__GERANT_Check15
};
static int **__GERANT_PCheckArray =  __GERANT_CheckArray;

/* INIT FUNCTION */

#ifndef NO_INIT
void GERANT_initialize () {
}
#endif

/* SHOW VARIABLE FUNCTION */

char* __GERANT_show_variable (int __V) {
extern struct __VariableEntry __GERANT_VariableTable[];
struct __VariableEntry* p_var = &__GERANT_VariableTable[__V];
if (p_var->type_code < 0) {return __PredefinedTypeToText(p_var->type_code, p_var->p_variable);
} else {
switch (p_var->type_code) {
default: return 0;
}
}
}

/* SET VARIABLE FUNCTION */

static void __GERANT_set_variable(int __Type, char* __pVar, char* __Text) {
}

/* CHECK VALUE FUNCTION */

static int __GERANT_check_value (int __Type, char* __Text) {
return 0;
}

/* SIMULATION TABLES */

struct __InstanceEntry __GERANT_InstanceTable [] = {
{"GERANT",0,"","gerant.strl",{1,1,1,0},{1,14,1,0},{0,0,0,0}},
};

struct __SignalEntry __GERANT_SignalTable [] = {
{"FIN",33,0,0,{1,3,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"C",1,1,0,{1,5,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"P",34,0,0,{1,6,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"MAX",34,0,0,{1,7,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"VIDE",34,0,0,{1,7,17,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"C_S",2,3,0,{1,8,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"P_S",34,0,0,{1,9,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"ST",2,4,0,{1,10,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"FS",2,5,0,{1,10,26,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

struct __InputEntry __GERANT_InputTable [] = {
{"FIN",19,0,0,-1,0,0,0,GERANT_IS_FIN,0,{1,3,11,0}},
{"C",67,"integer",0,-3,0,1,_check_integer,GERANT_IS_C,0,{1,5,11,0}}};

struct __VariableEntry __GERANT_VariableTable [] = {
{"__GERANT_V0","V0","boolean",-2,2,0,(char*)&__GERANT_V0,"FIN",0,0,0,{1,3,11,0}},
{"__GERANT_V1","V1","integer",-3,1,0,(char*)&__GERANT_V1,"C",0,0,0,{1,5,11,0}},
{"__GERANT_V2","V2","boolean",-2,2,0,(char*)&__GERANT_V2,"C",0,0,0,{1,5,11,0}},
{"__GERANT_V3","V3","integer",-3,1,0,(char*)&__GERANT_V3,"C_S",0,0,0,{1,8,12,0}},
{"__GERANT_V4","V4","integer",-3,1,0,(char*)&__GERANT_V4,"ST",0,0,0,{1,10,12,0}},
{"__GERANT_V5","V5","integer",-3,1,0,(char*)&__GERANT_V5,"FS",0,0,0,{1,10,26,0}}
};

struct __HaltEntry __GERANT_HaltTable [] = {
{{1,14,1,0}}
};


static void __GERANT__reset_input () {
__GERANT_V0 = _false;
__GERANT_V2 = _false;
}


/* MODULE DATA FOR SIMULATION */

int GERANT();
int GERANT_reset();

static struct __ModuleEntry __GERANT_ModuleData = {
"Simulation interface release 5","GERANT",
1,0,9,2,0,0,7,0,0,0,0,6,0,1,0,0,0,
__GERANT_HaltList,
__GERANT_AwaitedList,
__GERANT_EmittedList,
__GERANT_StartedList,
__GERANT_KilledList,
__GERANT_SuspendedList,
__GERANT_ActiveList,
0,0,
GERANT_initialize,GERANT,GERANT_reset,
__GERANT_show_variable,__GERANT_set_variable,__GERANT_check_value,0,
__GERANT_InstanceTable,
0,
__GERANT_SignalTable,__GERANT_InputTable,0,
0,0,
__GERANT_VariableTable,
0,
__GERANT_HaltTable,
0};

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __GERANT_R[1] = {_true};

/* AUTOMATON ENGINE */

int GERANT () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[3];

__GERANT_ModuleData.awaited_list = __GERANT_AwaitedList;
__ResetModuleEntryBeforeReaction();
if (__GERANT_R[0]) {
__AppendToList(__GERANT_EmittedList,6);
}
if (!(_true)) {
__CheckVariables(__GERANT_CheckArray[3]);__GERANT_A3();
#ifdef TRACE_ACTION
fprintf(stderr, "__GERANT_A3\n");
#endif
}
if (!(_true)) {
__CheckVariables(__GERANT_CheckArray[4]);__GERANT_A4();
#ifdef TRACE_ACTION
fprintf(stderr, "__GERANT_A4\n");
#endif
}
if (!(_true)) {
__CheckVariables(__GERANT_CheckArray[5]);__GERANT_A5();
#ifdef TRACE_ACTION
fprintf(stderr, "__GERANT_A5\n");
#endif
}
if (!(_true)) {
__CheckVariables(__GERANT_CheckArray[6]);__GERANT_A6();
#ifdef TRACE_ACTION
fprintf(stderr, "__GERANT_A6\n");
#endif
}
E[0] = __GERANT_R[0]&&!((__CheckVariables(__GERANT_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__GERANT_A2()));
if (E[0]) {
__CheckVariables(__GERANT_CheckArray[12]);__GERANT_A12();
#ifdef TRACE_ACTION
fprintf(stderr, "__GERANT_A12\n");
#endif
}
if (__GERANT_R[0]) {
__CheckVariables(__GERANT_CheckArray[13]);__GERANT_A13();
#ifdef TRACE_ACTION
fprintf(stderr, "__GERANT_A13\n");
#endif
}
if (__GERANT_R[0]) {
__CheckVariables(__GERANT_CheckArray[14]);__GERANT_A14();
#ifdef TRACE_ACTION
fprintf(stderr, "__GERANT_A14\n");
#endif
}
if (__GERANT_R[0]) {
__CheckVariables(__GERANT_CheckArray[15]);__GERANT_A15();
#ifdef TRACE_ACTION
fprintf(stderr, "__GERANT_A15\n");
#endif
}
if (__GERANT_R[0]) {
__CheckVariables(__GERANT_CheckArray[7]);__GERANT_A7();
#ifdef TRACE_ACTION
fprintf(stderr, "__GERANT_A7\n");
#endif
}
if (!(_true)) {
__CheckVariables(__GERANT_CheckArray[8]);__GERANT_A8();
#ifdef TRACE_ACTION
fprintf(stderr, "__GERANT_A8\n");
#endif
}
if (!(_true)) {
__CheckVariables(__GERANT_CheckArray[9]);__GERANT_A9();
#ifdef TRACE_ACTION
fprintf(stderr, "__GERANT_A9\n");
#endif
}
E[1] = __GERANT_R[0];
E[2] = !(_true);
__GERANT_R[0] = !(_true);
if (!E[2]) { __AppendToList(__GERANT_HaltList,0); }
__ResetModuleEntryAfterReaction();
__GERANT_ModuleData.awaited_list = __GERANT_AllAwaitedList;
__GERANT__reset_input();
return E[2];
}

/* AUTOMATON RESET */

int GERANT_reset () {
__GERANT_ModuleData.awaited_list = __GERANT_AwaitedList;
__ResetModuleEntry();
__GERANT_ModuleData.awaited_list = __GERANT_AllAwaitedList;
__GERANT_ModuleData.state = 0;
__GERANT_R[0] = _true;
__GERANT__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__GERANT_ModuleData
};
