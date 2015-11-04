#ifndef CAUTERIZE_DESCRIPTORS_H
#define CAUTERIZE_DESCRIPTORS_H

#include "cauterize_types.h"

#include <stdbool.h>
#include <stddef.h>

struct caut_field {
    char const * name;
    size_t field_index;
    bool data;
    int ref_id;
    size_t offset;
};

struct caut_primitive {
    size_t word_size;
};

struct caut_synonym {
    int ref_id;
};

struct caut_range {
    enum caut_tag tag;
    int64_t offset;
    uint64_t length;
    size_t word_size;
};

struct caut_enumeration {
    enum caut_tag tag;
    size_t length;
    size_t size;
};

struct caut_array {
    int ref_id;
    size_t length;
};

struct caut_vector {
    enum caut_tag tag;
    int ref_id;
    size_t max_length;
};

struct caut_record {
    size_t field_count;
    struct caut_field const * fields;
};

struct caut_union {
    enum caut_tag tag;
    size_t field_count;
    struct caut_field const * fields;
};

struct caut_combination {
    enum caut_tag tag;
    size_t field_count;
    struct caut_field const * fields;
};

union caut_prototype {
    struct caut_primitive c_primitive;
    struct caut_synonym c_synonym;
    struct caut_range c_range;
    struct caut_enumeration c_enumeration;
    struct caut_array c_array;
    struct caut_vector c_vector;
    struct caut_record c_record;
    struct caut_union c_union;
    struct caut_combination c_combination;
};

struct type_descriptor {
    char const * name;
    int type_id;
    enum caut_proto_tag prototype_tag;
    union caut_prototype prototype;
};

#define CAUT_PRIMITIVE_COUNT (11)
extern struct type_descriptor const primitive_descriptors[CAUT_PRIMITIVE_COUNT];

#endif /* CAUTERIZE_DESCRIPTORS_H */