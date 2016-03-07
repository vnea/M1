/* sscc : C CODE OF SORTED EQUATIONS CONSO - SIMULATION MODE */

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
#define __CONSO_GENERIC_TEST(TEST) return TEST;
typedef void (*__CONSO_APF)();
static __CONSO_APF *__CONSO_PActionArray;
static int **__CONSO_PCheckArray;
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

#include "conso.h"

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
#ifndef _num_DEFINED
#ifndef num
extern integer num;
#endif
#endif
#endif
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static boolean __CONSO_V0;
static boolean __CONSO_V1;
static integer __CONSO_V2;
static boolean __CONSO_V3;
static integer __CONSO_V4;
static integer __CONSO_V5;
static integer __CONSO_V6;

static unsigned short __CONSO_HaltList[3];
static unsigned short __CONSO_AwaitedList[6];
static unsigned short __CONSO_EmittedList[6];
static unsigned short __CONSO_StartedList[1];
static unsigned short __CONSO_KilledList[1];
static unsigned short __CONSO_SuspendedList[1];
static unsigned short __CONSO_ActiveList[1];
static unsigned short __CONSO_AllAwaitedList[6]={3,0,1,2};


/* INPUT FUNCTIONS */

void CONSO_I_FIN () {
__CONSO_V0 = _true;
}
void CONSO_IS_FIN () {
__CONSO_V0 = _true;
}
void CONSO_I_Ci () {
__CONSO_V1 = _true;
}
void CONSO_IS_Ci () {
__CONSO_V1 = _true;
}
void CONSO_I_C_S (integer __V) {
__WriteVariable(2);
__CONSO_V2 = __V;
__CONSO_V3 = _true;
}
void CONSO_IS_C_S (string __V) {
__WriteVariable(2);
_text_to_integer(&__CONSO_V2,__V);
__CONSO_V3 = _true;
}

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int CONSO_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

static int __CONSO_A1 () {
__CONSO_GENERIC_TEST(__CONSO_V0);
}
static int __CONSO_Check1 [] = {1,0,0};
static int __CONSO_A2 () {
__CONSO_GENERIC_TEST(__CONSO_V1);
}
static int __CONSO_Check2 [] = {1,0,0};
static int __CONSO_A3 () {
__CONSO_GENERIC_TEST(__CONSO_V3);
}
static int __CONSO_Check3 [] = {1,0,0};

/* OUTPUT ACTIONS */

static void __CONSO_A4 () {
#ifdef __OUTPUT
CONSO_O_C(__CONSO_V4);
#endif
__AppendToList(__CONSO_EmittedList,3);
}
static int __CONSO_Check4 [] = {1,0,0};
static void __CONSO_A5 () {
#ifdef __OUTPUT
CONSO_O_FC(__CONSO_V5);
#endif
__AppendToList(__CONSO_EmittedList,4);
}
static int __CONSO_Check5 [] = {1,0,0};

/* ASSIGNMENTS */

static void __CONSO_A6 () {
__CONSO_V0 = _false;
}
static int __CONSO_Check6 [] = {1,0,1,0};
static void __CONSO_A7 () {
__CONSO_V1 = _false;
}
static int __CONSO_Check7 [] = {1,0,1,1};
static void __CONSO_A8 () {
__CONSO_V3 = _false;
}
static int __CONSO_Check8 [] = {1,0,1,3};
static void __CONSO_A9 () {
__CONSO_V6 = 0;
}
static int __CONSO_Check9 [] = {1,0,1,6};
static void __CONSO_A10 () {
__CONSO_V4 = num;
}
static int __CONSO_Check10 [] = {1,0,1,4};
static void __CONSO_A11 () {
__CONSO_V6 = __CONSO_V6+1;
}
static int __CONSO_Check11 [] = {1,1,6,1,6};
static void __CONSO_A12 () {
__CONSO_V5 = __CONSO_V6;
}
static int __CONSO_Check12 [] = {1,1,6,1,5};

/* PROCEDURE CALLS */

/* CONDITIONS */

static int __CONSO_A13 () {
__CONSO_GENERIC_TEST(__CONSO_V2==num);
}
static int __CONSO_Check13 [] = {1,1,2,0};

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

static void __CONSO_A14 () {
;
__ResetVariable(2);
}
static int __CONSO_Check14 [] = {1,0,0};
static void __CONSO_A15 () {
;
__ResetVariable(4);
}
static int __CONSO_Check15 [] = {1,0,0};
static void __CONSO_A16 () {
;
__ResetVariable(5);
}
static int __CONSO_Check16 [] = {1,0,0};

/* ACTION SEQUENCES */


static int *__CONSO_CheckArray[] = {
0,
__CONSO_Check1,
__CONSO_Check2,
__CONSO_Check3,
__CONSO_Check4,
__CONSO_Check5,
__CONSO_Check6,
__CONSO_Check7,
__CONSO_Check8,
__CONSO_Check9,
__CONSO_Check10,
__CONSO_Check11,
__CONSO_Check12,
__CONSO_Check13,
__CONSO_Check14,
__CONSO_Check15,
__CONSO_Check16
};
static int **__CONSO_PCheckArray =  __CONSO_CheckArray;

/* INIT FUNCTION */

#ifndef NO_INIT
void CONSO_initialize () {
}
#endif

/* SHOW VARIABLE FUNCTION */

char* __CONSO_show_variable (int __V) {
extern struct __VariableEntry __CONSO_VariableTable[];
struct __VariableEntry* p_var = &__CONSO_VariableTable[__V];
if (p_var->type_code < 0) {return __PredefinedTypeToText(p_var->type_code, p_var->p_variable);
} else {
switch (p_var->type_code) {
default: return 0;
}
}
}

/* SET VARIABLE FUNCTION */

static void __CONSO_set_variable(int __Type, char* __pVar, char* __Text) {
}

/* CHECK VALUE FUNCTION */

static int __CONSO_check_value (int __Type, char* __Text) {
return 0;
}

/* SIMULATION TABLES */

struct __InstanceEntry __CONSO_InstanceTable [] = {
{"CONSO",0,"","conso.strl",{1,1,1,0},{1,21,1,0},{0,0,0,0}},
};

struct __SignalEntry __CONSO_SignalTable [] = {
{"FIN",33,0,0,{1,3,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Ci",33,0,0,{1,3,16,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"C_S",1,2,0,{1,3,20,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"C",2,4,0,{1,4,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"FC",2,5,0,{1,4,25,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

struct __InputEntry __CONSO_InputTable [] = {
{"FIN",19,0,0,-1,0,0,0,CONSO_IS_FIN,0,{1,3,11,0}},
{"Ci",71,0,0,-1,0,1,0,CONSO_IS_Ci,0,{1,3,16,0}},
{"C_S",43,"integer",0,-3,0,2,_check_integer,CONSO_IS_C_S,0,{1,3,20,0}}};

struct __VariableEntry __CONSO_VariableTable [] = {
{"__CONSO_V0","V0","boolean",-2,2,0,(char*)&__CONSO_V0,"FIN",0,0,0,{1,3,11,0}},
{"__CONSO_V1","V1","boolean",-2,2,0,(char*)&__CONSO_V1,"Ci",0,0,0,{1,3,16,0}},
{"__CONSO_V2","V2","integer",-3,1,0,(char*)&__CONSO_V2,"C_S",0,0,0,{1,3,20,0}},
{"__CONSO_V3","V3","boolean",-2,2,0,(char*)&__CONSO_V3,"C_S",0,0,0,{1,3,20,0}},
{"__CONSO_V4","V4","integer",-3,1,0,(char*)&__CONSO_V4,"C",0,0,0,{1,4,12,0}},
{"__CONSO_V5","V5","integer",-3,1,0,(char*)&__CONSO_V5,"FC",0,0,0,{1,4,25,0}},
{"__CONSO_V6","V6","integer",-3,0,0,(char*)&__CONSO_V6,"nbconso1",0,0,0,{1,7,9,0}}
};

struct __HaltEntry __CONSO_HaltTable [] = {
{{1,21,1,0}},
{{1,11,17,0}}
};


static void __CONSO__reset_input () {
__CONSO_V0 = _false;
__CONSO_V1 = _false;
__CONSO_V3 = _false;
}


/* MODULE DATA FOR SIMULATION */

int CONSO();
int CONSO_reset();

static struct __ModuleEntry __CONSO_ModuleData = {
"Simulation interface release 5","CONSO",
1,0,5,3,0,0,2,0,0,0,0,7,0,2,0,0,0,
__CONSO_HaltList,
__CONSO_AwaitedList,
__CONSO_EmittedList,
__CONSO_StartedList,
__CONSO_KilledList,
__CONSO_SuspendedList,
__CONSO_ActiveList,
0,0,
CONSO_initialize,CONSO,CONSO_reset,
__CONSO_show_variable,__CONSO_set_variable,__CONSO_check_value,0,
__CONSO_InstanceTable,
0,
__CONSO_SignalTable,__CONSO_InputTable,0,
0,0,
__CONSO_VariableTable,
0,
__CONSO_HaltTable,
0};

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __CONSO_R[2] = {_true,
 _false};

/* AUTOMATON ENGINE */

int CONSO () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[6];

__CONSO_ModuleData.awaited_list = __CONSO_AwaitedList;
__ResetModuleEntryBeforeReaction();
E[0] = __CONSO_R[0]&&!((__CheckVariables(__CONSO_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__CONSO_A3()));
if (E[0]) {
__CheckVariables(__CONSO_CheckArray[14]);__CONSO_A14();
#ifdef TRACE_ACTION
fprintf(stderr, "__CONSO_A14\n");
#endif
}
if (__CONSO_R[0]) {
__CheckVariables(__CONSO_CheckArray[15]);__CONSO_A15();
#ifdef TRACE_ACTION
fprintf(stderr, "__CONSO_A15\n");
#endif
}
if (__CONSO_R[0]) {
__CheckVariables(__CONSO_CheckArray[16]);__CONSO_A16();
#ifdef TRACE_ACTION
fprintf(stderr, "__CONSO_A16\n");
#endif
}
if (__CONSO_R[0]) {
__CheckVariables(__CONSO_CheckArray[9]);__CONSO_A9();
#ifdef TRACE_ACTION
fprintf(stderr, "__CONSO_A9\n");
#endif
}
E[1] = __CONSO_R[1]&&!(__CONSO_R[0]);
E[2] = E[1]&&!((__CheckVariables(__CONSO_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__CONSO_A1()));
E[2] = __CONSO_R[1]&&E[2];
E[3] = E[2]&&(__CheckVariables(__CONSO_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__CONSO_A3());
E[4] = E[3]&&(__CheckVariables(__CONSO_CheckArray[13]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 13\n"),
#endif
__CONSO_A13());
if (E[4]) {
__CheckVariables(__CONSO_CheckArray[11]);__CONSO_A11();
#ifdef TRACE_ACTION
fprintf(stderr, "__CONSO_A11\n");
#endif
}
E[3] = __CONSO_R[0]||E[4]||(E[3]&&!(E[4]));
if (E[3]) {
__AppendToList(__CONSO_EmittedList,3);
}
if (E[3]) {
__CheckVariables(__CONSO_CheckArray[10]);__CONSO_A10();
#ifdef TRACE_ACTION
fprintf(stderr, "__CONSO_A10\n");
#endif
}
if (E[3]) {
__CheckVariables(__CONSO_CheckArray[4]);__CONSO_A4();
#ifdef TRACE_ACTION
fprintf(stderr, "__CONSO_A4\n");
#endif
}
E[1] = E[1]&&(__CheckVariables(__CONSO_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__CONSO_A1());
if (E[1]) {
__AppendToList(__CONSO_EmittedList,4);
}
if (E[1]) {
__CheckVariables(__CONSO_CheckArray[12]);__CONSO_A12();
#ifdef TRACE_ACTION
fprintf(stderr, "__CONSO_A12\n");
#endif
}
if (E[1]) {
__CheckVariables(__CONSO_CheckArray[5]);__CONSO_A5();
#ifdef TRACE_ACTION
fprintf(stderr, "__CONSO_A5\n");
#endif
}
E[5] = E[1];
E[2] = E[2]&&!((__CheckVariables(__CONSO_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__CONSO_A3()));
__CONSO_R[1] = E[3]||(__CONSO_R[1]&&E[2]);
E[2] = __CONSO_R[1];
__CONSO_R[0] = !(_true);
if (__CONSO_R[1]) { __AppendToList(__CONSO_HaltList,1); }
if (!E[2]) { __AppendToList(__CONSO_HaltList,0); }
__ResetModuleEntryAfterReaction();
__CONSO_ModuleData.awaited_list = __CONSO_AllAwaitedList;
__CONSO__reset_input();
return E[2];
}

/* AUTOMATON RESET */

int CONSO_reset () {
__CONSO_ModuleData.awaited_list = __CONSO_AwaitedList;
__ResetModuleEntry();
__CONSO_ModuleData.awaited_list = __CONSO_AllAwaitedList;
__CONSO_ModuleData.state = 0;
__CONSO_R[0] = _true;
__CONSO_R[1] = _false;
__CONSO__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__CONSO_ModuleData
};
