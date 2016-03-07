/* sscc : C CODE OF SORTED EQUATIONS PROD - SIMULATION MODE */

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
#define __PROD_GENERIC_TEST(TEST) return TEST;
typedef void (*__PROD_APF)();
static __PROD_APF *__PROD_PActionArray;
static int **__PROD_PCheckArray;
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
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static boolean __PROD_V0;
static boolean __PROD_V1;
static integer __PROD_V2;
static integer __PROD_V3;
static integer __PROD_V4;

static unsigned short __PROD_HaltList[4];
static unsigned short __PROD_AwaitedList[5];
static unsigned short __PROD_EmittedList[5];
static unsigned short __PROD_StartedList[1];
static unsigned short __PROD_KilledList[1];
static unsigned short __PROD_SuspendedList[1];
static unsigned short __PROD_ActiveList[1];
static unsigned short __PROD_AllAwaitedList[5]={2,0,1};


/* INPUT FUNCTIONS */

void PROD_I_FIN () {
__PROD_V0 = _true;
}
void PROD_IS_FIN () {
__PROD_V0 = _true;
}
void PROD_I_P_S () {
__PROD_V1 = _true;
}
void PROD_IS_P_S () {
__PROD_V1 = _true;
}

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int PROD_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

static int __PROD_A1 () {
__PROD_GENERIC_TEST(__PROD_V0);
}
static int __PROD_Check1 [] = {1,0,0};
static int __PROD_A2 () {
__PROD_GENERIC_TEST(__PROD_V1);
}
static int __PROD_Check2 [] = {1,0,0};

/* OUTPUT ACTIONS */

static void __PROD_A3 () {
#ifdef __OUTPUT
PROD_O_P();
#endif
__AppendToList(__PROD_EmittedList,2);
}
static int __PROD_Check3 [] = {1,0,0};
static void __PROD_A4 () {
#ifdef __OUTPUT
PROD_O_FP(__PROD_V2);
#endif
__AppendToList(__PROD_EmittedList,3);
}
static int __PROD_Check4 [] = {1,0,0};

/* ASSIGNMENTS */

static void __PROD_A5 () {
__PROD_V0 = _false;
}
static int __PROD_Check5 [] = {1,0,1,0};
static void __PROD_A6 () {
__PROD_V1 = _false;
}
static int __PROD_Check6 [] = {1,0,1,1};
static void __PROD_A7 () {
__PROD_V3 = 0;
}
static int __PROD_Check7 [] = {1,0,1,3};
static void __PROD_A8 () {
__PROD_V4 = 3;
}
static int __PROD_Check8 [] = {1,0,1,4};
static void __PROD_A9 () {
__PROD_V3 = __PROD_V3+1;
}
static int __PROD_Check9 [] = {1,1,3,1,3};
static void __PROD_A10 () {
__PROD_V2 = __PROD_V3;
}
static int __PROD_Check10 [] = {1,1,3,1,2};

/* PROCEDURE CALLS */

/* CONDITIONS */

static int __PROD_A11 () {
__PROD_GENERIC_TEST(__PROD_V4>0);
}
static int __PROD_Check11 [] = {1,1,4,0};

/* DECREMENTS */

static int __PROD_A12 () {
__PROD_GENERIC_TEST(__DSZ(__PROD_V4));
}
static int __PROD_Check12 [] = {1,1,4,1,4};

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

static void __PROD_A13 () {
;
__ResetVariable(2);
}
static int __PROD_Check13 [] = {1,0,0};

/* ACTION SEQUENCES */


static int *__PROD_CheckArray[] = {
0,
__PROD_Check1,
__PROD_Check2,
__PROD_Check3,
__PROD_Check4,
__PROD_Check5,
__PROD_Check6,
__PROD_Check7,
__PROD_Check8,
__PROD_Check9,
__PROD_Check10,
__PROD_Check11,
__PROD_Check12,
__PROD_Check13
};
static int **__PROD_PCheckArray =  __PROD_CheckArray;

/* INIT FUNCTION */

#ifndef NO_INIT
void PROD_initialize () {
}
#endif

/* SHOW VARIABLE FUNCTION */

char* __PROD_show_variable (int __V) {
extern struct __VariableEntry __PROD_VariableTable[];
struct __VariableEntry* p_var = &__PROD_VariableTable[__V];
if (p_var->type_code < 0) {return __PredefinedTypeToText(p_var->type_code, p_var->p_variable);
} else {
switch (p_var->type_code) {
default: return 0;
}
}
}

/* SET VARIABLE FUNCTION */

static void __PROD_set_variable(int __Type, char* __pVar, char* __Text) {
}

/* CHECK VALUE FUNCTION */

static int __PROD_check_value (int __Type, char* __Text) {
return 0;
}

/* SIMULATION TABLES */

struct __InstanceEntry __PROD_InstanceTable [] = {
{"PROD",0,"","prod.strl",{1,1,1,0},{1,22,1,0},{0,0,0,0}},
};

struct __SignalEntry __PROD_SignalTable [] = {
{"FIN",33,0,0,{1,3,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"P_S",33,0,0,{1,3,16,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"P",34,0,0,{1,4,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"FP",2,2,0,{1,4,15,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

struct __InputEntry __PROD_InputTable [] = {
{"FIN",19,0,0,-1,0,0,0,PROD_IS_FIN,0,{1,3,11,0}},
{"P_S",56,0,0,-1,0,1,0,PROD_IS_P_S,0,{1,3,16,0}}};

struct __VariableEntry __PROD_VariableTable [] = {
{"__PROD_V0","V0","boolean",-2,2,0,(char*)&__PROD_V0,"FIN",0,0,0,{1,3,11,0}},
{"__PROD_V1","V1","boolean",-2,2,0,(char*)&__PROD_V1,"P_S",0,0,0,{1,3,16,0}},
{"__PROD_V2","V2","integer",-3,1,0,(char*)&__PROD_V2,"FP",0,0,0,{1,4,15,0}},
{"__PROD_V3","V3","integer",-3,0,0,(char*)&__PROD_V3,"nbprod",0,0,0,{1,6,9,0}},
{"__PROD_V4","V4","integer",-3,3,0,(char*)&__PROD_V4,"0",0,0,0,{1,9,24,0}}
};

struct __HaltEntry __PROD_HaltTable [] = {
{{1,22,1,0}},
{{1,10,21,0}},
{{1,15,17,0}}
};


static void __PROD__reset_input () {
__PROD_V0 = _false;
__PROD_V1 = _false;
}


/* MODULE DATA FOR SIMULATION */

int PROD();
int PROD_reset();

static struct __ModuleEntry __PROD_ModuleData = {
"Simulation interface release 5","PROD",
1,0,4,2,0,0,2,0,0,0,0,5,0,3,0,0,0,
__PROD_HaltList,
__PROD_AwaitedList,
__PROD_EmittedList,
__PROD_StartedList,
__PROD_KilledList,
__PROD_SuspendedList,
__PROD_ActiveList,
0,0,
PROD_initialize,PROD,PROD_reset,
__PROD_show_variable,__PROD_set_variable,__PROD_check_value,0,
__PROD_InstanceTable,
0,
__PROD_SignalTable,__PROD_InputTable,0,
0,0,
__PROD_VariableTable,
0,
__PROD_HaltTable,
0};

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __PROD_R[3] = {_true,
 _false,
 _false};

/* AUTOMATON ENGINE */

int PROD () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[8];

__PROD_ModuleData.awaited_list = __PROD_AwaitedList;
__ResetModuleEntryBeforeReaction();
E[0] = (__PROD_R[1]||__PROD_R[2])&&!(__PROD_R[0]);
E[1] = E[0]&&!((__CheckVariables(__PROD_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__PROD_A1()));
E[2] = __PROD_R[1]&&E[1];
E[3] = E[2]&&(__CheckVariables(__PROD_CheckArray[12]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 12\n"),
#endif
__PROD_A12());
if (__PROD_R[0]) {
__CheckVariables(__PROD_CheckArray[13]);__PROD_A13();
#ifdef TRACE_ACTION
fprintf(stderr, "__PROD_A13\n");
#endif
}
if (__PROD_R[0]) {
__CheckVariables(__PROD_CheckArray[7]);__PROD_A7();
#ifdef TRACE_ACTION
fprintf(stderr, "__PROD_A7\n");
#endif
}
E[1] = __PROD_R[2]&&E[1];
E[4] = E[1]&&(__CheckVariables(__PROD_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__PROD_A2());
E[4] = __PROD_R[0]||E[4];
if (E[4]) {
__CheckVariables(__PROD_CheckArray[8]);__PROD_A8();
#ifdef TRACE_ACTION
fprintf(stderr, "__PROD_A8\n");
#endif
}
E[5] = E[4]&&(__CheckVariables(__PROD_CheckArray[11]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 11\n"),
#endif
__PROD_A11());
E[6] = E[3]||(E[4]&&!(E[5]));
if (E[6]) {
__AppendToList(__PROD_EmittedList,2);
}
if (E[6]) {
__CheckVariables(__PROD_CheckArray[3]);__PROD_A3();
#ifdef TRACE_ACTION
fprintf(stderr, "__PROD_A3\n");
#endif
}
E[0] = E[0]&&(__CheckVariables(__PROD_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__PROD_A1());
if (E[0]) {
__AppendToList(__PROD_EmittedList,3);
}
if (E[0]) {
__CheckVariables(__PROD_CheckArray[10]);__PROD_A10();
#ifdef TRACE_ACTION
fprintf(stderr, "__PROD_A10\n");
#endif
}
if (E[0]) {
__CheckVariables(__PROD_CheckArray[4]);__PROD_A4();
#ifdef TRACE_ACTION
fprintf(stderr, "__PROD_A4\n");
#endif
}
E[7] = E[0];
__PROD_R[1] = E[5]||(E[2]&&!(E[3]));
if (E[6]) {
__CheckVariables(__PROD_CheckArray[9]);__PROD_A9();
#ifdef TRACE_ACTION
fprintf(stderr, "__PROD_A9\n");
#endif
}
E[1] = E[1]&&!((__CheckVariables(__PROD_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__PROD_A2()));
__PROD_R[2] = E[6]||(__PROD_R[2]&&E[1]);
E[1] = __PROD_R[1]||__PROD_R[2];
__PROD_R[0] = !(_true);
if (__PROD_R[1]) { __AppendToList(__PROD_HaltList,1); }
if (__PROD_R[2]) { __AppendToList(__PROD_HaltList,2); }
if (!E[1]) { __AppendToList(__PROD_HaltList,0); }
__ResetModuleEntryAfterReaction();
__PROD_ModuleData.awaited_list = __PROD_AllAwaitedList;
__PROD__reset_input();
return E[1];
}

/* AUTOMATON RESET */

int PROD_reset () {
__PROD_ModuleData.awaited_list = __PROD_AwaitedList;
__ResetModuleEntry();
__PROD_ModuleData.awaited_list = __PROD_AllAwaitedList;
__PROD_ModuleData.state = 0;
__PROD_R[0] = _true;
__PROD_R[1] = _false;
__PROD_R[2] = _false;
__PROD__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__PROD_ModuleData
};
