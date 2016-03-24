/* sscc : C CODE OF SORTED EQUATIONS medele - SIMULATION MODE */

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
#define __medele_GENERIC_TEST(TEST) return TEST;
typedef void (*__medele_APF)();
static __medele_APF *__medele_PActionArray;
static int **__medele_PCheckArray;
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

static boolean __medele_V0;
static boolean __medele_V1;
static boolean __medele_V2;
static boolean __medele_V3;
static boolean __medele_V4;
static boolean __medele_V5;
static boolean __medele_V6;
static integer __medele_V7;
static boolean __medele_V8;
static boolean __medele_V9;
static boolean __medele_V10;
static boolean __medele_V11;
static integer __medele_V12;
static integer __medele_V13;
static integer __medele_V14;
static char __medele_V15[STRLEN];
static integer __medele_V16;
static float __medele_V17;
static float __medele_V18;
static boolean __medele_V19;
static integer __medele_V20;
static integer __medele_V21;

static unsigned short __medele_HaltList[6];
static unsigned short __medele_AwaitedList[31];
static unsigned short __medele_EmittedList[31];
static unsigned short __medele_StartedList[1];
static unsigned short __medele_KilledList[1];
static unsigned short __medele_SuspendedList[1];
static unsigned short __medele_ActiveList[1];
static unsigned short __medele_AllAwaitedList[31]={11,0,1,2,3,4,5,6,7,8,9,10};


/* INPUT FUNCTIONS */

void medele_I_ENTER () {
__medele_V0 = _true;
}
void medele_IS_ENTER () {
__medele_V0 = _true;
}
void medele_I_ESCAPE () {
__medele_V1 = _true;
}
void medele_IS_ESCAPE () {
__medele_V1 = _true;
}
void medele_I_LEFT () {
__medele_V2 = _true;
}
void medele_IS_LEFT () {
__medele_V2 = _true;
}
void medele_I_RIGHT () {
__medele_V3 = _true;
}
void medele_IS_RIGHT () {
__medele_V3 = _true;
}
void medele_I_A_isMoving () {
__medele_V4 = _true;
}
void medele_IS_A_isMoving () {
__medele_V4 = _true;
}
void medele_I_B_isMoving () {
__medele_V5 = _true;
}
void medele_IS_B_isMoving () {
__medele_V5 = _true;
}
void medele_I_C_isMoving () {
__medele_V6 = _true;
}
void medele_IS_C_isMoving () {
__medele_V6 = _true;
}
void medele_I_Distance (integer __V) {
__WriteVariable(7);
__medele_V7 = __V;
__medele_V8 = _true;
}
void medele_IS_Distance (string __V) {
__WriteVariable(7);
_text_to_integer(&__medele_V7,__V);
__medele_V8 = _true;
}
void medele_I_Depassement_Lumiere () {
__medele_V9 = _true;
}
void medele_IS_Depassement_Lumiere () {
__medele_V9 = _true;
}
void medele_I_Sound () {
__medele_V10 = _true;
}
void medele_IS_Sound () {
__medele_V10 = _true;
}
void medele_I_Touch () {
__medele_V11 = _true;
}
void medele_IS_Touch () {
__medele_V11 = _true;
}
static void medele_I_Light (float __V) {
__WriteVariable(18);
__medele_V18 = __V;
}
static void medele_IS_Light (string __V) {
__WriteVariable(18);
_text_to_float(&__medele_V18,__V);
;
}

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int medele_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

static int __medele_A1 () {
__medele_GENERIC_TEST(__medele_V0);
}
static int __medele_Check1 [] = {1,0,0};
static int __medele_A2 () {
__medele_GENERIC_TEST(__medele_V1);
}
static int __medele_Check2 [] = {1,0,0};
static int __medele_A3 () {
__medele_GENERIC_TEST(__medele_V2);
}
static int __medele_Check3 [] = {1,0,0};
static int __medele_A4 () {
__medele_GENERIC_TEST(__medele_V3);
}
static int __medele_Check4 [] = {1,0,0};
static int __medele_A5 () {
__medele_GENERIC_TEST(__medele_V4);
}
static int __medele_Check5 [] = {1,0,0};
static int __medele_A6 () {
__medele_GENERIC_TEST(__medele_V5);
}
static int __medele_Check6 [] = {1,0,0};
static int __medele_A7 () {
__medele_GENERIC_TEST(__medele_V6);
}
static int __medele_Check7 [] = {1,0,0};
static int __medele_A8 () {
__medele_GENERIC_TEST(__medele_V8);
}
static int __medele_Check8 [] = {1,0,0};
static int __medele_A9 () {
__medele_GENERIC_TEST(__medele_V9);
}
static int __medele_Check9 [] = {1,0,0};
static int __medele_A10 () {
__medele_GENERIC_TEST(__medele_V10);
}
static int __medele_Check10 [] = {1,0,0};
static int __medele_A11 () {
__medele_GENERIC_TEST(__medele_V11);
}
static int __medele_Check11 [] = {1,0,0};

/* OUTPUT ACTIONS */

static void __medele_A12 () {
#ifdef __OUTPUT
medele_O_A_Vitesse(__medele_V12);
#endif
__AppendToList(__medele_EmittedList,11);
}
static int __medele_Check12 [] = {1,0,0};
static void __medele_A13 () {
#ifdef __OUTPUT
medele_O_B_Vitesse(__medele_V13);
#endif
__AppendToList(__medele_EmittedList,12);
}
static int __medele_Check13 [] = {1,0,0};
static void __medele_A14 () {
#ifdef __OUTPUT
medele_O_C_Vitesse(__medele_V14);
#endif
__AppendToList(__medele_EmittedList,13);
}
static int __medele_Check14 [] = {1,0,0};
static void __medele_A15 () {
#ifdef __OUTPUT
medele_O_A_Avance();
#endif
__AppendToList(__medele_EmittedList,14);
}
static int __medele_Check15 [] = {1,0,0};
static void __medele_A16 () {
#ifdef __OUTPUT
medele_O_B_Avance();
#endif
__AppendToList(__medele_EmittedList,15);
}
static int __medele_Check16 [] = {1,0,0};
static void __medele_A17 () {
#ifdef __OUTPUT
medele_O_C_Avance();
#endif
__AppendToList(__medele_EmittedList,16);
}
static int __medele_Check17 [] = {1,0,0};
static void __medele_A18 () {
#ifdef __OUTPUT
medele_O_tmpsig();
#endif
__AppendToList(__medele_EmittedList,17);
}
static int __medele_Check18 [] = {1,0,0};
static void __medele_A19 () {
#ifdef __OUTPUT
medele_O_LCD(__medele_V15);
#endif
__AppendToList(__medele_EmittedList,18);
}
static int __medele_Check19 [] = {1,0,0};
static void __medele_A20 () {
#ifdef __OUTPUT
medele_O_LCDint(__medele_V16);
#endif
__AppendToList(__medele_EmittedList,19);
}
static int __medele_Check20 [] = {1,0,0};
static void __medele_A21 () {
#ifdef __OUTPUT
medele_O_LCDfloat(__medele_V17);
#endif
__AppendToList(__medele_EmittedList,20);
}
static int __medele_Check21 [] = {1,0,0};
static void __medele_A22 () {
#ifdef __OUTPUT
medele_O_A_Recul();
#endif
__AppendToList(__medele_EmittedList,21);
}
static int __medele_Check22 [] = {1,0,0};
static void __medele_A23 () {
#ifdef __OUTPUT
medele_O_B_Recul();
#endif
__AppendToList(__medele_EmittedList,22);
}
static int __medele_Check23 [] = {1,0,0};
static void __medele_A24 () {
#ifdef __OUTPUT
medele_O_C_Recul();
#endif
__AppendToList(__medele_EmittedList,23);
}
static int __medele_Check24 [] = {1,0,0};
static void __medele_A25 () {
#ifdef __OUTPUT
medele_O_A_Stop();
#endif
__AppendToList(__medele_EmittedList,24);
}
static int __medele_Check25 [] = {1,0,0};
static void __medele_A26 () {
#ifdef __OUTPUT
medele_O_B_Stop();
#endif
__AppendToList(__medele_EmittedList,25);
}
static int __medele_Check26 [] = {1,0,0};
static void __medele_A27 () {
#ifdef __OUTPUT
medele_O_C_Stop();
#endif
__AppendToList(__medele_EmittedList,26);
}
static int __medele_Check27 [] = {1,0,0};
static void __medele_A28 () {
#ifdef __OUTPUT
medele_O_Bip();
#endif
__AppendToList(__medele_EmittedList,27);
}
static int __medele_Check28 [] = {1,0,0};

/* ASSIGNMENTS */

static void __medele_A29 () {
__medele_V0 = _false;
}
static int __medele_Check29 [] = {1,0,1,0};
static void __medele_A30 () {
__medele_V1 = _false;
}
static int __medele_Check30 [] = {1,0,1,1};
static void __medele_A31 () {
__medele_V2 = _false;
}
static int __medele_Check31 [] = {1,0,1,2};
static void __medele_A32 () {
__medele_V3 = _false;
}
static int __medele_Check32 [] = {1,0,1,3};
static void __medele_A33 () {
__medele_V4 = _false;
}
static int __medele_Check33 [] = {1,0,1,4};
static void __medele_A34 () {
__medele_V5 = _false;
}
static int __medele_Check34 [] = {1,0,1,5};
static void __medele_A35 () {
__medele_V6 = _false;
}
static int __medele_Check35 [] = {1,0,1,6};
static void __medele_A36 () {
__medele_V8 = _false;
}
static int __medele_Check36 [] = {1,0,1,8};
static void __medele_A37 () {
__medele_V9 = _false;
}
static int __medele_Check37 [] = {1,0,1,9};
static void __medele_A38 () {
__medele_V10 = _false;
}
static int __medele_Check38 [] = {1,0,1,10};
static void __medele_A39 () {
__medele_V11 = _false;
}
static int __medele_Check39 [] = {1,0,1,11};
static void __medele_A40 () {
__medele_V19 = _false;
}
static int __medele_Check40 [] = {1,0,1,19};
static void __medele_A41 () {
__medele_V20 = 30;
}
static int __medele_Check41 [] = {1,0,1,20};
static void __medele_A42 () {
__medele_V21 = 20;
}
static int __medele_Check42 [] = {1,0,1,21};

/* PROCEDURE CALLS */

/* CONDITIONS */

static int __medele_A43 () {
__medele_GENERIC_TEST(__medele_V18<(float)470.0);
}
static int __medele_Check43 [] = {1,1,18,0};

/* DECREMENTS */

static int __medele_A44 () {
__medele_GENERIC_TEST(__DSZ(__medele_V20));
}
static int __medele_Check44 [] = {1,1,20,1,20};
static int __medele_A45 () {
__medele_GENERIC_TEST(__DSZ(__medele_V21));
}
static int __medele_Check45 [] = {1,1,21,1,21};

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

static void __medele_A46 () {
;
__ResetVariable(7);
}
static int __medele_Check46 [] = {1,0,0};
static void __medele_A47 () {
;
__ResetVariable(12);
}
static int __medele_Check47 [] = {1,0,0};
static void __medele_A48 () {
;
__ResetVariable(13);
}
static int __medele_Check48 [] = {1,0,0};
static void __medele_A49 () {
;
__ResetVariable(14);
}
static int __medele_Check49 [] = {1,0,0};
static void __medele_A50 () {
;
__ResetVariable(15);
}
static int __medele_Check50 [] = {1,0,0};
static void __medele_A51 () {
;
__ResetVariable(16);
}
static int __medele_Check51 [] = {1,0,0};
static void __medele_A52 () {
;
__ResetVariable(17);
}
static int __medele_Check52 [] = {1,0,0};

/* ACTION SEQUENCES */


static int *__medele_CheckArray[] = {
0,
__medele_Check1,
__medele_Check2,
__medele_Check3,
__medele_Check4,
__medele_Check5,
__medele_Check6,
__medele_Check7,
__medele_Check8,
__medele_Check9,
__medele_Check10,
__medele_Check11,
__medele_Check12,
__medele_Check13,
__medele_Check14,
__medele_Check15,
__medele_Check16,
__medele_Check17,
__medele_Check18,
__medele_Check19,
__medele_Check20,
__medele_Check21,
__medele_Check22,
__medele_Check23,
__medele_Check24,
__medele_Check25,
__medele_Check26,
__medele_Check27,
__medele_Check28,
__medele_Check29,
__medele_Check30,
__medele_Check31,
__medele_Check32,
__medele_Check33,
__medele_Check34,
__medele_Check35,
__medele_Check36,
__medele_Check37,
__medele_Check38,
__medele_Check39,
__medele_Check40,
__medele_Check41,
__medele_Check42,
__medele_Check43,
__medele_Check44,
__medele_Check45,
__medele_Check46,
__medele_Check47,
__medele_Check48,
__medele_Check49,
__medele_Check50,
__medele_Check51,
__medele_Check52
};
static int **__medele_PCheckArray =  __medele_CheckArray;

/* INIT FUNCTION */

#ifndef NO_INIT
void medele_initialize () {
}
#endif

/* SHOW VARIABLE FUNCTION */

char* __medele_show_variable (int __V) {
extern struct __VariableEntry __medele_VariableTable[];
struct __VariableEntry* p_var = &__medele_VariableTable[__V];
if (p_var->type_code < 0) {return __PredefinedTypeToText(p_var->type_code, p_var->p_variable);
} else {
switch (p_var->type_code) {
default: return 0;
}
}
}

/* SET VARIABLE FUNCTION */

static void __medele_set_variable(int __Type, char* __pVar, char* __Text) {
}

/* CHECK VALUE FUNCTION */

static int __medele_check_value (int __Type, char* __Text) {
return 0;
}

/* SIMULATION TABLES */

struct __InstanceEntry __medele_InstanceTable [] = {
{"medele",0,"","modele_nea.strl",{1,1,1,0},{1,92,1,0},{0,0,0,0}},
};

struct __SignalEntry __medele_SignalTable [] = {
{"ENTER",33,0,0,{1,3,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"ESCAPE",33,0,0,{1,3,15,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"LEFT",33,0,0,{1,3,23,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"RIGHT",33,0,0,{1,3,29,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"A_isMoving",33,0,0,{1,4,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"B_isMoving",33,0,0,{1,4,20,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"C_isMoving",33,0,0,{1,4,32,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Distance",1,7,0,{1,5,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Depassement_Lumiere",33,0,0,{1,5,28,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Sound",33,0,0,{1,5,49,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Touch",33,0,0,{1,6,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"A_Vitesse",2,12,0,{1,8,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"B_Vitesse",2,13,0,{1,8,29,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"C_Vitesse",2,14,0,{1,8,50,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"A_Avance",34,0,0,{1,9,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"B_Avance",34,0,0,{1,9,18,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"C_Avance",34,0,0,{1,9,28,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"tmpsig",34,0,0,{1,10,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"LCD",2,15,0,{1,11,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"LCDint",2,16,0,{1,11,22,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"LCDfloat",2,17,0,{1,11,40,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"A_Recul",34,0,0,{1,12,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"B_Recul",34,0,0,{1,12,17,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"C_Recul",34,0,0,{1,12,26,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"A_Stop",34,0,0,{1,13,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"B_Stop",34,0,0,{1,13,16,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"C_Stop",34,0,0,{1,13,24,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Bip",34,0,0,{1,14,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Light",4,18,0,{1,15,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Fin",40,0,0,{1,54,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

struct __InputEntry __medele_InputTable [] = {
{"ENTER",79,0,0,-1,0,0,0,medele_IS_ENTER,0,{1,3,8,0}},
{"ESCAPE",29,0,0,-1,0,1,0,medele_IS_ESCAPE,0,{1,3,15,0}},
{"LEFT",97,0,0,-1,0,2,0,medele_IS_LEFT,0,{1,3,23,0}},
{"RIGHT",79,0,0,-1,0,3,0,medele_IS_RIGHT,0,{1,3,29,0}},
{"A_isMoving",95,0,0,-1,0,4,0,medele_IS_A_isMoving,0,{1,4,8,0}},
{"B_isMoving",96,0,0,-1,0,5,0,medele_IS_B_isMoving,0,{1,4,20,0}},
{"C_isMoving",97,0,0,-1,0,6,0,medele_IS_C_isMoving,0,{1,4,32,0}},
{"Distance",3,"integer",0,-3,0,7,_check_integer,medele_IS_Distance,0,{1,5,8,0}},
{"Depassement_Lumiere",44,0,0,-1,0,8,0,medele_IS_Depassement_Lumiere,0,{1,5,28,0}},
{"Sound",16,0,0,-1,0,9,0,medele_IS_Sound,0,{1,5,49,0}},
{"Touch",10,0,0,-1,0,10,0,medele_IS_Touch,0,{1,6,8,0}},
{"Light",100,"float",1,-5,0,28,_check_float,medele_IS_Light,0,{1,15,8,0}}};

struct __VariableEntry __medele_VariableTable [] = {
{"__medele_V0","V0","boolean",-2,2,0,(char*)&__medele_V0,"ENTER",0,0,0,{1,3,8,0}},
{"__medele_V1","V1","boolean",-2,2,0,(char*)&__medele_V1,"ESCAPE",0,0,0,{1,3,15,0}},
{"__medele_V2","V2","boolean",-2,2,0,(char*)&__medele_V2,"LEFT",0,0,0,{1,3,23,0}},
{"__medele_V3","V3","boolean",-2,2,0,(char*)&__medele_V3,"RIGHT",0,0,0,{1,3,29,0}},
{"__medele_V4","V4","boolean",-2,2,0,(char*)&__medele_V4,"A_isMoving",0,0,0,{1,4,8,0}},
{"__medele_V5","V5","boolean",-2,2,0,(char*)&__medele_V5,"B_isMoving",0,0,0,{1,4,20,0}},
{"__medele_V6","V6","boolean",-2,2,0,(char*)&__medele_V6,"C_isMoving",0,0,0,{1,4,32,0}},
{"__medele_V7","V7","integer",-3,1,0,(char*)&__medele_V7,"Distance",0,0,0,{1,5,8,0}},
{"__medele_V8","V8","boolean",-2,2,0,(char*)&__medele_V8,"Distance",0,0,0,{1,5,8,0}},
{"__medele_V9","V9","boolean",-2,2,0,(char*)&__medele_V9,"Depassement_Lumiere",0,0,0,{1,5,28,0}},
{"__medele_V10","V10","boolean",-2,2,0,(char*)&__medele_V10,"Sound",0,0,0,{1,5,49,0}},
{"__medele_V11","V11","boolean",-2,2,0,(char*)&__medele_V11,"Touch",0,0,0,{1,6,8,0}},
{"__medele_V12","V12","integer",-3,1,0,(char*)&__medele_V12,"A_Vitesse",0,0,0,{1,8,8,0}},
{"__medele_V13","V13","integer",-3,1,0,(char*)&__medele_V13,"B_Vitesse",0,0,0,{1,8,29,0}},
{"__medele_V14","V14","integer",-3,1,0,(char*)&__medele_V14,"C_Vitesse",0,0,0,{1,8,50,0}},
{"__medele_V15","V15","string",-4,1,0,__medele_V15,"LCD",0,0,0,{1,11,8,0}},
{"__medele_V16","V16","integer",-3,1,0,(char*)&__medele_V16,"LCDint",0,0,0,{1,11,22,0}},
{"__medele_V17","V17","float",-5,1,0,(char*)&__medele_V17,"LCDfloat",0,0,0,{1,11,40,0}},
{"__medele_V18","V18","float",-5,4,0,(char*)&__medele_V18,"Light",0,0,0,{1,15,8,0}},
{"__medele_V19","V19","boolean",-2,5,0,(char*)&__medele_V19,"Light",0,0,0,{1,15,8,0}},
{"__medele_V20","V20","integer",-3,3,0,(char*)&__medele_V20,"0",0,0,0,{1,66,18,0}},
{"__medele_V21","V21","integer",-3,3,0,(char*)&__medele_V21,"0",0,0,0,{1,73,19,0}}
};

struct __HaltEntry __medele_HaltTable [] = {
{{1,92,1,0}},
{{1,64,21,0}},
{{1,68,13,0}},
{{1,71,13,0}},
{{1,73,13,0}}
};


static void __medele__reset_input () {
__medele_V0 = _false;
__medele_V1 = _false;
__medele_V2 = _false;
__medele_V3 = _false;
__medele_V4 = _false;
__medele_V5 = _false;
__medele_V6 = _false;
__medele_V8 = _false;
__medele_V9 = _false;
__medele_V10 = _false;
__medele_V11 = _false;
__medele_V19 = _false;
}


/* MODULE DATA FOR SIMULATION */

int medele();
int medele_reset();

static struct __ModuleEntry __medele_ModuleData = {
"Simulation interface release 5","medele",
1,0,30,12,0,1,17,1,0,0,0,22,0,5,0,0,0,
__medele_HaltList,
__medele_AwaitedList,
__medele_EmittedList,
__medele_StartedList,
__medele_KilledList,
__medele_SuspendedList,
__medele_ActiveList,
0,0,
medele_initialize,medele,medele_reset,
__medele_show_variable,__medele_set_variable,__medele_check_value,0,
__medele_InstanceTable,
0,
__medele_SignalTable,__medele_InputTable,0,
0,0,
__medele_VariableTable,
0,
__medele_HaltTable,
0};

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __medele_R[5] = {_true,
 _false,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int medele () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[9];

__medele_ModuleData.awaited_list = __medele_AwaitedList;
__ResetModuleEntryBeforeReaction();
if (!(_true)) {
__CheckVariables(__medele_CheckArray[12]);__medele_A12();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A12\n");
#endif
}
if (!(_true)) {
__CheckVariables(__medele_CheckArray[13]);__medele_A13();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A13\n");
#endif
}
if (!(_true)) {
__CheckVariables(__medele_CheckArray[14]);__medele_A14();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A14\n");
#endif
}
E[0] = __medele_R[0]&&!((__CheckVariables(__medele_CheckArray[8]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__medele_A8()));
if (E[0]) {
__CheckVariables(__medele_CheckArray[46]);__medele_A46();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A46\n");
#endif
}
if (__medele_R[0]) {
__CheckVariables(__medele_CheckArray[47]);__medele_A47();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A47\n");
#endif
}
if (__medele_R[0]) {
__CheckVariables(__medele_CheckArray[48]);__medele_A48();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A48\n");
#endif
}
if (__medele_R[0]) {
__CheckVariables(__medele_CheckArray[49]);__medele_A49();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A49\n");
#endif
}
if (__medele_R[0]) {
__CheckVariables(__medele_CheckArray[50]);__medele_A50();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A50\n");
#endif
}
if (__medele_R[0]) {
__CheckVariables(__medele_CheckArray[51]);__medele_A51();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A51\n");
#endif
}
if (__medele_R[0]) {
__CheckVariables(__medele_CheckArray[52]);__medele_A52();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A52\n");
#endif
}
E[1] = (__medele_R[1]||__medele_R[2]||__medele_R[3]||__medele_R[4])&&!(__medele_R[0]);
E[2] = E[1]&&!((__CheckVariables(__medele_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__medele_A2()));
E[3] = __medele_R[4]&&E[2];
E[4] = E[3]&&(__CheckVariables(__medele_CheckArray[45]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 45\n"),
#endif
__medele_A45());
if (__medele_R[0]||E[4]) {
__AppendToList(__medele_EmittedList,14);
}
if (__medele_R[0]||E[4]) {
__CheckVariables(__medele_CheckArray[15]);__medele_A15();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A15\n");
#endif
}
if (!(_true)) {
__CheckVariables(__medele_CheckArray[16]);__medele_A16();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A16\n");
#endif
}
E[5] = __medele_R[2]&&E[2];
if (E[5]) {
__AppendToList(__medele_EmittedList,24);
}
if (__medele_R[0]||E[5]) {
__AppendToList(__medele_EmittedList,16);
}
if (__medele_R[0]||E[5]) {
__CheckVariables(__medele_CheckArray[17]);__medele_A17();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A17\n");
#endif
}
if (!(_true)) {
__CheckVariables(__medele_CheckArray[18]);__medele_A18();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A18\n");
#endif
}
if (!(_true)) {
__CheckVariables(__medele_CheckArray[19]);__medele_A19();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A19\n");
#endif
}
if (!(_true)) {
__CheckVariables(__medele_CheckArray[20]);__medele_A20();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A20\n");
#endif
}
if (!(_true)) {
__CheckVariables(__medele_CheckArray[21]);__medele_A21();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A21\n");
#endif
}
if (!(_true)) {
__CheckVariables(__medele_CheckArray[22]);__medele_A22();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A22\n");
#endif
}
if (!(_true)) {
__CheckVariables(__medele_CheckArray[23]);__medele_A23();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A23\n");
#endif
}
if (!(_true)) {
__CheckVariables(__medele_CheckArray[24]);__medele_A24();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A24\n");
#endif
}
if (E[5]) {
__CheckVariables(__medele_CheckArray[25]);__medele_A25();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A25\n");
#endif
}
if (!(_true)) {
__CheckVariables(__medele_CheckArray[26]);__medele_A26();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A26\n");
#endif
}
if (!(_true)) {
__CheckVariables(__medele_CheckArray[27]);__medele_A27();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A27\n");
#endif
}
if (!(_true)) {
__CheckVariables(__medele_CheckArray[28]);__medele_A28();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A28\n");
#endif
}
E[6] = __medele_R[1]&&E[2];
__medele_R[2] = E[6]&&(__CheckVariables(__medele_CheckArray[44]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 44\n"),
#endif
__medele_A44());
E[7] = __medele_R[0]||E[4];
if (E[7]) {
__CheckVariables(__medele_CheckArray[41]);__medele_A41();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A41\n");
#endif
}
E[6] = (__medele_R[1]&&E[6]&&!(__medele_R[2]))||E[7];
E[8] = E[6]&&(__CheckVariables(__medele_CheckArray[43]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 43\n"),
#endif
__medele_A43());
if (E[8]) {
__AppendToList(__medele_EmittedList,29);
}
E[1] = E[1]&&(__CheckVariables(__medele_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__medele_A2());
E[1] = E[1];
__medele_R[1] = E[8]||(E[6]&&!(E[8]));
E[2] = __medele_R[3]&&E[2];
if (E[2]) {
__CheckVariables(__medele_CheckArray[42]);__medele_A42();
#ifdef TRACE_ACTION
fprintf(stderr, "__medele_A42\n");
#endif
}
__medele_R[4] = E[2]||(__medele_R[4]&&E[3]&&!(E[4]));
E[3] = __medele_R[1]||__medele_R[2]||E[5]||__medele_R[4];
__medele_R[0] = !(_true);
if (__medele_R[1]) { __AppendToList(__medele_HaltList,1); }
if (__medele_R[2]) { __AppendToList(__medele_HaltList,2); }
__medele_R[3] = E[5];
if (__medele_R[3]) { __AppendToList(__medele_HaltList,3); }
if (__medele_R[4]) { __AppendToList(__medele_HaltList,4); }
if (!E[3]) { __AppendToList(__medele_HaltList,0); }
__ResetModuleEntryAfterReaction();
__medele_ModuleData.awaited_list = __medele_AllAwaitedList;
__medele__reset_input();
return E[3];
}

/* AUTOMATON RESET */

int medele_reset () {
__medele_ModuleData.awaited_list = __medele_AwaitedList;
__ResetModuleEntry();
__medele_ModuleData.awaited_list = __medele_AllAwaitedList;
__medele_ModuleData.state = 0;
__medele_R[0] = _true;
__medele_R[1] = _false;
__medele_R[2] = _false;
__medele_R[3] = _false;
__medele_R[4] = _false;
__medele__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__medele_ModuleData
};
