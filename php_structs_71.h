#ifndef __php_structs_71_h
#define __php_structs_71_h

#include <stdint.h>

typedef struct _zend_executor_globals_71 zend_executor_globals_71;
typedef struct _zend_execute_data_71     zend_execute_data_71;
typedef union  _zend_function_71         zend_function_71;
typedef struct _zend_class_entry_71      zend_class_entry_71;
typedef struct _zend_string_71           zend_string_71;
typedef struct _zend_op_71               zend_op_71;
typedef struct _sapi_globals_struct_71   sapi_globals_struct_71;
typedef struct _sapi_request_info_71     sapi_request_info_71;

// Assumes 8-byte pointers

                                                // offset   length
                                                //
struct __attribute__((__packed__)) _zend_executor_globals_71 {
    uint8_t pad0[480];                          // 0        +480
    zend_execute_data_71 *current_execute_data; // 480      +8
};

struct __attribute__((__packed__)) _zend_execute_data_71 {
    zend_op_71 *opline;                         // 0        +8
    uint8_t pad0[16];                           // 8        +16
    zend_function_71 *func;                     // 24       +8
    uint8_t pad1[16];                           // 32       +16
    zend_execute_data_71 *prev_execute_data;    // 48       +8
};

union __attribute__((__packed__)) _zend_function_71 {
    uint8_t type;                               // 0        +8
    struct {
        uint8_t pad0[8];                        // 0        +8
        zend_string_71 *function_name;          // 8        +8
        zend_class_entry_71 *scope;             // 16       +8
    } common;
    struct {
        uint8_t pad1[120];                      // 0        +120
        zend_string_71 *filename;               // 120      +8
    } op_array;
};

struct __attribute__((__packed__)) _zend_class_entry_71 {
    uint8_t pad0[8];                            // 0        +8
    zend_function_71 *name;                     // 8        +8
};

struct __attribute__((__packed__)) _zend_string_71 {
    uint8_t pad0[16];                           // 0        +16
    size_t len;                                 // 16       +8
    char *val;                                  // 24       +8
};

struct __attribute__((__packed__)) _zend_op_71 {
    uint8_t pad0[24];                           // 0        +24
    uint32_t lineno;                            // 24       +4
};

struct __attribute__((__packed__)) _sapi_request_info_71 {
    uint8_t pad0[8];                            // 0        +8
    char *query_string;                         // 8        +8
    char *cookie_data;                          // 16       +8
    uint8_t pad1[8];                            // 24       +8
    char *path_translated;                      // 32       +8
    char *request_uri;                          // 40       +8
};

struct __attribute__((__packed__)) _sapi_globals_struct_71 {
    uint8_t pad0[8];                            // 0        +8
    sapi_request_info_71 request_info;          // 8        +48
    uint8_t pad1[384];                          // 56       +384
    double global_request_time;                 // 440      +8
};

#endif