/* sscc : C CODE OF SORTED EQUATIONS ZUDNB - SIMULATION MODE */

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
#define __ZUDNB_GENERIC_TEST(TEST) return TEST;
typedef void (*__ZUDNB_APF)();
static __ZUDNB_APF *__ZUDNB_PActionArray;
static int **__ZUDNB_PCheckArray;
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

static boolean __ZUDNB_V0;
static boolean __ZUDNB_V1;
static boolean __ZUDNB_V2;
static integer __ZUDNB_V3;
static integer __ZUDNB_V4;

static unsigned short __ZUDNB_HaltList[4];
static unsigned short __ZUDNB_AwaitedList[5];
static unsigned short __ZUDNB_EmittedList[5];
static unsigned short __ZUDNB_StartedList[1];
static unsigned short __ZUDNB_KilledList[1];
static unsigned short __ZUDNB_SuspendedList[1];
static unsigned short __ZUDNB_ActiveList[1];
static unsigned short __ZUDNB_AllAwaitedList[5]={3,0,1,2};


/* INPUT FUNCTIONS */

void ZUDNB_I_ZERO () {
__ZUDNB_V0 = _true;
}
void ZUDNB_IS_ZERO () {
__ZUDNB_V0 = _true;
}
void ZUDNB_I_UN () {
__ZUDNB_V1 = _true;
}
void ZUDNB_IS_UN () {
__ZUDNB_V1 = _true;
}
void ZUDNB_I_DEUX () {
__ZUDNB_V2 = _true;
}
void ZUDNB_IS_DEUX () {
__ZUDNB_V2 = _true;
}

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int ZUDNB_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

static int __ZUDNB_A1 () {
__ZUDNB_GENERIC_TEST(__ZUDNB_V0);
}
static int __ZUDNB_Check1 [] = {1,0,0};
static int __ZUDNB_A2 () {
__ZUDNB_GENERIC_TEST(__ZUDNB_V1);
}
static int __ZUDNB_Check2 [] = {1,0,0};
static int __ZUDNB_A3 () {
__ZUDNB_GENERIC_TEST(__ZUDNB_V2);
}
static int __ZUDNB_Check3 [] = {1,0,0};

/* OUTPUT ACTIONS */

static void __ZUDNB_A4 () {
#ifdef __OUTPUT
ZUDNB_O_NB(__ZUDNB_V3);
#endif
__AppendToList(__ZUDNB_EmittedList,3);
}
static int __ZUDNB_Check4 [] = {1,0,0};

/* ASSIGNMENTS */

static void __ZUDNB_A5 () {
__ZUDNB_V0 = _false;
}
static int __ZUDNB_Check5 [] = {1,0,1,0};
static void __ZUDNB_A6 () {
__ZUDNB_V1 = _false;
}
static int __ZUDNB_Check6 [] = {1,0,1,1};
static void __ZUDNB_A7 () {
__ZUDNB_V2 = _false;
}
static int __ZUDNB_Check7 [] = {1,0,1,2};
static void __ZUDNB_A8 () {
__ZUDNB_V4 = 0;
}
static int __ZUDNB_Check8 [] = {1,0,1,4};
static void __ZUDNB_A9 () {
__ZUDNB_V4 = 0;
}
static int __ZUDNB_Check9 [] = {1,0,1,4};
static void __ZUDNB_A10 () {
__ZUDNB_V4 = __ZUDNB_V4+1;
}
static int __ZUDNB_Check10 [] = {1,1,4,1,4};
static void __ZUDNB_A11 () {
__ZUDNB_V4 = __ZUDNB_V4+2;
}
static int __ZUDNB_Check11 [] = {1,1,4,1,4};
static void __ZUDNB_A12 () {
__ZUDNB_V3 = __ZUDNB_V4;
}
static int __ZUDNB_Check12 [] = {1,1,4,1,3};

/* PROCEDURE CALLS */

/* CONDITIONS */

static int __ZUDNB_A13 () {
__ZUDNB_GENERIC_TEST((__ZUDNB_V4%3)==0);
}
static int __ZUDNB_Check13 [] = {1,1,4,0};

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

static void __ZUDNB_A14 () {
;
__ResetVariable(3);
}
static int __ZUDNB_Check14 [] = {1,0,0};

/* ACTION SEQUENCES */


static int *__ZUDNB_CheckArray[] = {
0,
__ZUDNB_Check1,
__ZUDNB_Check2,
__ZUDNB_Check3,
__ZUDNB_Check4,
__ZUDNB_Check5,
__ZUDNB_Check6,
__ZUDNB_Check7,
__ZUDNB_Check8,
__ZUDNB_Check9,
__ZUDNB_Check10,
__ZUDNB_Check11,
__ZUDNB_Check12,
__ZUDNB_Check13,
__ZUDNB_Check14
};
static int **__ZUDNB_PCheckArray =  __ZUDNB_CheckArray;

/* INIT FUNCTION */

#ifndef NO_INIT
void ZUDNB_initialize () {
}
#endif

/* SHOW VARIABLE FUNCTION */

char* __ZUDNB_show_variable (int __V) {
extern struct __VariableEntry __ZUDNB_VariableTable[];
struct __VariableEntry* p_var = &__ZUDNB_VariableTable[__V];
if (p_var->type_code < 0) {return __PredefinedTypeToText(p_var->type_code, p_var->p_variable);
} else {
switch (p_var->type_code) {
default: return 0;
}
}
}

/* SET VARIABLE FUNCTION */

static void __ZUDNB_set_variable(int __Type, char* __pVar, char* __Text) {
}

/* CHECK VALUE FUNCTION */

static int __ZUDNB_check_value (int __Type, char* __Text) {
return 0;
}

/* SIMULATION TABLES */

struct __InstanceEntry __ZUDNB_InstanceTable [] = {
{"ZUDNB",0,"","exo1.strl",{1,1,1,0},{1,27,1,0},{0,0,0,0}},
};

struct __SignalEntry __ZUDNB_SignalTable [] = {
{"ZERO",33,0,0,{1,3,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"UN",33,0,0,{1,3,17,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"DEUX",33,0,0,{1,3,21,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"NB",2,3,0,{1,4,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

struct __InputEntry __ZUDNB_InputTable [] = {
{"ZERO",17,0,0,-1,0,0,0,ZUDNB_IS_ZERO,0,{1,3,11,0}},
{"UN",62,0,0,-1,0,1,0,ZUDNB_IS_UN,0,{1,3,17,0}},
{"DEUX",7,0,0,-1,0,2,0,ZUDNB_IS_DEUX,0,{1,3,21,0}}};

struct __VariableEntry __ZUDNB_VariableTable [] = {
{"__ZUDNB_V0","V0","boolean",-2,2,0,(char*)&__ZUDNB_V0,"ZERO",0,0,0,{1,3,11,0}},
{"__ZUDNB_V1","V1","boolean",-2,2,0,(char*)&__ZUDNB_V1,"UN",0,0,0,{1,3,17,0}},
{"__ZUDNB_V2","V2","boolean",-2,2,0,(char*)&__ZUDNB_V2,"DEUX",0,0,0,{1,3,21,0}},
{"__ZUDNB_V3","V3","integer",-3,1,0,(char*)&__ZUDNB_V3,"NB",0,0,0,{1,4,12,0}},
{"__ZUDNB_V4","V4","integer",-3,0,0,(char*)&__ZUDNB_V4,"cpt",0,0,0,{1,6,9,0}}
};

struct __HaltEntry __ZUDNB_HaltTable [] = {
{{1,27,1,0}},
{{1,10,17,0}},
{{1,24,9,0}}
};


static void __ZUDNB__reset_input () {
__ZUDNB_V0 = _false;
__ZUDNB_V1 = _false;
__ZUDNB_V2 = _false;
}


/* MODULE DATA FOR SIMULATION */

int ZUDNB();
int ZUDNB_reset();

static struct __ModuleEntry __ZUDNB_ModuleData = {
"Simulation interface release 5","ZUDNB",
1,0,4,3,0,0,1,0,0,0,0,5,0,3,0,0,0,
__ZUDNB_HaltList,
__ZUDNB_AwaitedList,
__ZUDNB_EmittedList,
__ZUDNB_StartedList,
__ZUDNB_KilledList,
__ZUDNB_SuspendedList,
__ZUDNB_ActiveList,
0,0,
ZUDNB_initialize,ZUDNB,ZUDNB_reset,
__ZUDNB_show_variable,__ZUDNB_set_variable,__ZUDNB_check_value,0,
__ZUDNB_InstanceTable,
0,
__ZUDNB_SignalTable,__ZUDNB_InputTable,0,
0,0,
__ZUDNB_VariableTable,
0,
__ZUDNB_HaltTable,
0};

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __ZUDNB_R[2] = {_true,
 _false};

/* AUTOMATON ENGINE */

int ZUDNB () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[8];

__ZUDNB_ModuleData.awaited_list = __ZUDNB_AwaitedList;
__ResetModuleEntryBeforeReaction();
E[0] = __ZUDNB_R[1]&&!(__ZUDNB_R[0]);
E[1] = E[0]&&!((__CheckVariables(__ZUDNB_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ZUDNB_A1()));
E[1] = __ZUDNB_R[1]&&E[1];
E[2] = (__CheckVariables(__ZUDNB_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__ZUDNB_A2())||(__CheckVariables(__ZUDNB_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__ZUDNB_A3());
E[3] = E[1]&&E[2];
E[4] = E[3]&&(__CheckVariables(__ZUDNB_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__ZUDNB_A2());
if (E[4]) {
__CheckVariables(__ZUDNB_CheckArray[10]);__ZUDNB_A10();
#ifdef TRACE_ACTION
fprintf(stderr, "__ZUDNB_A10\n");
#endif
}
E[3] = E[3]&&!((__CheckVariables(__ZUDNB_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__ZUDNB_A2()));
E[3] = E[4]||E[3];
E[5] = E[3]&&(__CheckVariables(__ZUDNB_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__ZUDNB_A3());
if (E[5]) {
__CheckVariables(__ZUDNB_CheckArray[11]);__ZUDNB_A11();
#ifdef TRACE_ACTION
fprintf(stderr, "__ZUDNB_A11\n");
#endif
}
E[3] = E[3]&&!((__CheckVariables(__ZUDNB_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__ZUDNB_A3()));
E[3] = E[5]||E[3];
E[6] = E[3]&&(__CheckVariables(__ZUDNB_CheckArray[13]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 13\n"),
#endif
__ZUDNB_A13());
if (E[6]) {
__AppendToList(__ZUDNB_EmittedList,3);
}
if (E[6]) {
__CheckVariables(__ZUDNB_CheckArray[12]);__ZUDNB_A12();
#ifdef TRACE_ACTION
fprintf(stderr, "__ZUDNB_A12\n");
#endif
}
if (E[6]) {
__CheckVariables(__ZUDNB_CheckArray[4]);__ZUDNB_A4();
#ifdef TRACE_ACTION
fprintf(stderr, "__ZUDNB_A4\n");
#endif
}
if (__ZUDNB_R[0]) {
__CheckVariables(__ZUDNB_CheckArray[14]);__ZUDNB_A14();
#ifdef TRACE_ACTION
fprintf(stderr, "__ZUDNB_A14\n");
#endif
}
E[7] = !(_true);
if (__ZUDNB_R[0]) {
__CheckVariables(__ZUDNB_CheckArray[8]);__ZUDNB_A8();
#ifdef TRACE_ACTION
fprintf(stderr, "__ZUDNB_A8\n");
#endif
}
E[0] = E[0]&&(__CheckVariables(__ZUDNB_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ZUDNB_A1());
E[0] = __ZUDNB_R[0]||E[0];
if (E[0]) {
__CheckVariables(__ZUDNB_CheckArray[9]);__ZUDNB_A9();
#ifdef TRACE_ACTION
fprintf(stderr, "__ZUDNB_A9\n");
#endif
}
__ZUDNB_R[1] = E[0]||E[6]||(E[3]&&!(E[6]))||(__ZUDNB_R[1]&&E[1]&&!(E[2]));
E[2] = __ZUDNB_R[1];
__ZUDNB_R[0] = !(_true);
if (__ZUDNB_R[1]) { __AppendToList(__ZUDNB_HaltList,1); }
if (!E[2]) { __AppendToList(__ZUDNB_HaltList,0); }
__ResetModuleEntryAfterReaction();
__ZUDNB_ModuleData.awaited_list = __ZUDNB_AllAwaitedList;
__ZUDNB__reset_input();
return E[2];
}

/* AUTOMATON RESET */

int ZUDNB_reset () {
__ZUDNB_ModuleData.awaited_list = __ZUDNB_AwaitedList;
__ResetModuleEntry();
__ZUDNB_ModuleData.awaited_list = __ZUDNB_AllAwaitedList;
__ZUDNB_ModuleData.state = 0;
__ZUDNB_R[0] = _true;
__ZUDNB_R[1] = _false;
__ZUDNB__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__ZUDNB_ModuleData
};
