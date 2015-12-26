
#include <cstdlib>
#include <cstdio>
#include <cstdarg>
#include <iostream>
#include <qd/qd_real.h>
#include <qd/fpu.h>
#include <omp.h>
#include <stdexcept>
#include <cuda.h>
#include <vector>
#include <memory>

#include "cuda_util.h"
#include "test_util.h"
#include "test_common.h"
#include "gqdtest.h"

using namespace std;
using namespace CUDAUtil;


/* general macro utilities */
#define FUNC_START_MSG printf("%s start ............................................\n", __func__);
#define FUNC_END_MSG   printf("%s done  ...........................................\n\n", __func__);

template<class c_t, class g_t>
void test_sqrt(const unsigned int numElement) {

    FUNC_START_MSG;

    c_t* dd_in = new c_t[numElement];
    c_t* gold_out = new c_t[numElement];
    c_t low = "0.0";
    c_t high = "1.0";
    randArray(dd_in, numElement, low, high);
    g_t* gdd_in = new g_t[numElement];
    g_t* gdd_out = new g_t[numElement];
    qd2gqd(dd_in, gdd_in, numElement);


    unsigned int numBlock = 128;
    unsigned int numThread = 128;
    device_math(gdd_in, numElement, gdd_out, SQRT, numBlock, numThread);
    c_t* gpu_out = new c_t[numElement];
    gqd2qd(gdd_out, gpu_out, numElement);

    INIT_TIMER;
    START_TIMER;
#pragma omp parallel for
    for (unsigned int i = 0; i < numElement; i++) {
        gold_out[i] = sqrt(dd_in[i]);
    }
    END_TIMER;
    PRINT_TIMER_SEC("CPU sqrt");

    checkTwoArray(gold_out, gpu_out, numElement);

    delete[] dd_in;
    delete[] gold_out;
    delete[] gdd_in;
    delete[] gdd_out;
    delete[] gpu_out;

    FUNC_END_MSG;
}

template<class c_t, class g_t>
void test_exp(const unsigned int numElement) {

    FUNC_START_MSG;


    c_t* dd_in = new c_t[numElement];
    c_t* gold_out = new c_t[numElement];
    c_t low = "0.0";
    c_t high = "1.0";
    randArray(dd_in, numElement, low, high);
    g_t* gdd_in = new g_t[numElement];
    g_t* gdd_out = new g_t[numElement];
    qd2gqd(dd_in, gdd_in, numElement);


    unsigned int numBlock = 128;
    unsigned int numThread = 128;
    device_math(gdd_in, numElement, gdd_out, EXP, numBlock, numThread);
    c_t* gpu_out = new c_t[numElement];
    gqd2qd(gdd_out, gpu_out, numElement);

    INIT_TIMER;
    START_TIMER;
#pragma omp parallel for
    for (unsigned int i = 0; i < numElement; i++) {
        gold_out[i] = exp(dd_in[i]);
    }
    END_TIMER;
    PRINT_TIMER_SEC("CPU exp");

    checkTwoArray(gold_out, gpu_out, numElement);

    delete[] dd_in;
    delete[] gold_out;
    delete[] gdd_in;
    delete[] gdd_out;
    delete[] gpu_out;

    FUNC_END_MSG;
}

template<class c_t, class g_t>
void test_log(const unsigned int numElement) {

    FUNC_START_MSG;

    c_t* dd_in = new c_t[numElement];
    c_t* gold_out = new c_t[numElement];
    c_t low = "0.0";
    c_t high = "1.0";
    randArray(dd_in, numElement, low, high);
    g_t* gdd_in = new g_t[numElement];
    g_t* gdd_out = new g_t[numElement];
    qd2gqd(dd_in, gdd_in, numElement);


    unsigned int numBlock = 128;
    unsigned int numThread = 128;
    device_math(gdd_in, numElement, gdd_out, LOG, numBlock, numThread);
    c_t* gpu_out = new c_t[numElement];
    gqd2qd(gdd_out, gpu_out, numElement);


    INIT_TIMER;
    START_TIMER;
#pragma omp parallel for
    for (unsigned int i = 0; i < numElement; i++) {
        gold_out[i] = log(dd_in[i]);
    }
    END_TIMER;
    PRINT_TIMER_SEC("CPU log");

    checkTwoArray(gold_out, gpu_out, numElement);

    delete[] dd_in;
    delete[] gold_out;
    delete[] gdd_in;
    delete[] gdd_out;
    delete[] gpu_out;

    FUNC_END_MSG;
}

template<class c_t, class g_t>
void test_sin(const unsigned int numElement) {

    FUNC_START_MSG;

    c_t* dd_in = new c_t[numElement];
    c_t* gold_out = new c_t[numElement];
    c_t low = "0.0";
    c_t high = "1.0";
    randArray(dd_in, numElement, low, high);
    g_t* gdd_in = new g_t[numElement];
    g_t* gdd_out = new g_t[numElement];
    qd2gqd(dd_in, gdd_in, numElement);


    unsigned int numBlock = 128;
    unsigned int numThread = 128;
    device_math(gdd_in, numElement, gdd_out, SIN, numBlock, numThread);
    c_t* gpu_out = new c_t[numElement];
    gqd2qd(gdd_out, gpu_out, numElement);


    INIT_TIMER;
    START_TIMER;
#pragma omp parallel for
    for (unsigned int i = 0; i < numElement; i++) {
        gold_out[i] = sin(dd_in[i]);
    }
    END_TIMER;
    PRINT_TIMER_SEC("CPU sin");

    checkTwoArray(gold_out, gpu_out, numElement);

    delete[] dd_in;
    delete[] gold_out;
    delete[] gdd_in;
    delete[] gdd_out;
    delete[] gpu_out;

    FUNC_END_MSG;
}

template<class c_t, class g_t>
void test_acos(const unsigned int numElement) {

    FUNC_START_MSG;

    c_t* dd_in = new c_t[numElement];
    c_t* gold_out = new c_t[numElement];
    c_t low = "-1.0";
    c_t high = "1.0";
    randArray(dd_in, numElement, low, high);
    g_t* gdd_in = new g_t[numElement];
    g_t* gdd_out = new g_t[numElement];
    qd2gqd(dd_in, gdd_in, numElement);


    unsigned int numBlock = 128;
    unsigned int numThread = 128;
    device_math(gdd_in, numElement, gdd_out, ACOS, numBlock, numThread);
    c_t* gpu_out = new c_t[numElement];
    gqd2qd(gdd_out, gpu_out, numElement);


    INIT_TIMER;
    START_TIMER;
#pragma omp parallel for
    for (unsigned int i = 0; i < numElement; i++) {
        gold_out[i] = acos(dd_in[i]);
    }
    END_TIMER;
    PRINT_TIMER_SEC("CPU acos");

    checkTwoArray(gold_out, gpu_out, numElement);

    delete[] dd_in;
    delete[] gold_out;
    delete[] gdd_in;
    delete[] gdd_out;
    delete[] gpu_out;

    FUNC_END_MSG;
}

template<class c_t, class g_t>
void test_asin(const unsigned int numElement) {

    FUNC_START_MSG;

    c_t* dd_in = new c_t[numElement];
    c_t* gold_out = new c_t[numElement];
    c_t low = "-1.0";
    c_t high = "1.0";
    randArray(dd_in, numElement, low, high);
    g_t* gdd_in = new g_t[numElement];
    g_t* gdd_out = new g_t[numElement];
    qd2gqd(dd_in, gdd_in, numElement);


    unsigned int numBlock = 128;
    unsigned int numThread = 128;
    device_math(gdd_in, numElement, gdd_out, ASIN, numBlock, numThread);
    c_t* gpu_out = new c_t[numElement];
    gqd2qd(gdd_out, gpu_out, numElement);


    INIT_TIMER;
    START_TIMER;
#pragma omp parallel for
    for (unsigned int i = 0; i < numElement; i++) {
        gold_out[i] = asin(dd_in[i]);
    }
    END_TIMER;
    PRINT_TIMER_SEC("CPU asin");

    checkTwoArray(gold_out, gpu_out, numElement);

    delete[] dd_in;
    delete[] gold_out;
    delete[] gdd_in;
    delete[] gdd_out;
    delete[] gpu_out;

    FUNC_END_MSG;
}

template<class c_t, class g_t>
void test_cos(unsigned int numElement) {

    FUNC_START_MSG;

    c_t* dd_in = new c_t[numElement];
    c_t* gold_out = new c_t[numElement];
    c_t low = "0.0";
    c_t high = "1.0";
    randArray(dd_in, numElement, low, high);
    g_t* gdd_in = new g_t[numElement];
    g_t* gdd_out = new g_t[numElement];
    qd2gqd(dd_in, gdd_in, numElement);


    unsigned int numBlock = 128;
    unsigned int numThread = 128;
    device_math(gdd_in, numElement, gdd_out, COS, numBlock, numThread);
    c_t* gpu_out = new c_t[numElement];
    gqd2qd(gdd_out, gpu_out, numElement);


    INIT_TIMER;
    START_TIMER;
#pragma omp parallel for
    for (unsigned int i = 0; i < numElement; i++) {
        gold_out[i] = cos(dd_in[i]);
    }
    END_TIMER;
    PRINT_TIMER_SEC("CPU cos");

    checkTwoArray(gold_out, gpu_out, numElement);

    delete[] dd_in;
    delete[] gold_out;
    delete[] gdd_in;
    delete[] gdd_out;
    delete[] gpu_out;

    FUNC_END_MSG;
}

template<class c_t, class g_t>
void test_tan(unsigned int numElement) {

    FUNC_START_MSG;

    c_t* dd_in = new c_t[numElement];
    c_t* gold_out = new c_t[numElement];
    c_t low = "0.0";
    c_t high = "1.0";
    randArray(dd_in, numElement, low, high);
    g_t* gdd_in = new g_t[numElement];
    g_t* gdd_out = new g_t[numElement];
    qd2gqd(dd_in, gdd_in, numElement);


    unsigned int numBlock = 128;
    unsigned int numThread = 128;
    device_math(gdd_in, numElement, gdd_out, TAN, numBlock, numThread);
    c_t* gpu_out = new c_t[numElement];
    gqd2qd(gdd_out, gpu_out, numElement);


    INIT_TIMER;
    START_TIMER;
#pragma omp parallel for
    for (unsigned int i = 0; i < numElement; i++) {
        gold_out[i] = tan(dd_in[i]);
    }
    END_TIMER;
    PRINT_TIMER_SEC("CPU tan");

    checkTwoArray(gold_out, gpu_out, numElement);

    delete[] dd_in;
    delete[] gold_out;
    delete[] gdd_in;
    delete[] gdd_out;
    delete[] gpu_out;

    FUNC_END_MSG;
}

/*
template<class c_t, class g_t>
void test_atan(unsigned int numElement) {

        FUNC_START_MSG;

        c_t* dd_in = new c_t[numElement];
        c_t* gold_out = new c_t[numElement];
        c_t low = "0.0";
        c_t high = "1.0";
        randArray(dd_in, numElement, low, high);
        g_t* gdd_in = new g_t[numElement];
        g_t* gdd_out = new g_t[numElement];
        qd2gqd(dd_in, gdd_in, numElement);


        unsigned int numBlock = 128;
        unsigned int numThread = 128;
        device_math(gdd_in, numElement, gdd_out, ATAN, numBlock, numThread);
        c_t* gpu_out = new c_t[numElement];
        gqd2qd(gdd_out, gpu_out, numElement);


        INIT_TIMER;
        START_TIMER;
#pragma omp parallel for
        for(unsigned int i = 0; i < numElement; i++) {
                gold_out[i] = atan(dd_in[i]);
        }
        END_TIMER;
        PRINT_TIMER_SEC("CPU tan");

        checkTwoArray(gold_out, gpu_out, numElement);

        delete[] dd_in;
        delete[] gold_out;
        delete[] gdd_in;
        delete[] gdd_out;
        delete[] gpu_out;

        FUNC_END_MSG;
}
 */


template<class c_t, class g_t>
void test_add(const unsigned int numElement) {

    FUNC_START_MSG;

    c_t* dd_in1 = new c_t[numElement];
    c_t* dd_in2 = new c_t[numElement];
    c_t* gold_out = new c_t[numElement];
    c_t low = "-1.0";
    c_t high = "1.0";
    randArray(dd_in1, numElement, low, high, 777);
    randArray(dd_in2, numElement, low, high, 888);
    g_t* gdd_in1 = new g_t[numElement];
    g_t* gdd_in2 = new g_t[numElement];
    g_t* gdd_out = new g_t[numElement];
    qd2gqd(dd_in1, gdd_in1, numElement);
    qd2gqd(dd_in2, gdd_in2, numElement);


    unsigned int numBlock = 128;
    unsigned int numThread = 128;
    device_basic(gdd_in1, gdd_in2, gdd_out, numElement, ADD, numBlock, numThread);
    c_t* gpu_out = new c_t[numElement];
    gqd2qd(gdd_out, gpu_out, numElement);

    INIT_TIMER;
    START_TIMER;
#pragma omp parallel for
    for (unsigned int i = 0; i < numElement; i++) {
        gold_out[i] = dd_in1[i] + dd_in2[i];
    }
    END_TIMER;
    PRINT_TIMER_SEC("CPU add");

    checkTwoArray(gold_out, gpu_out, numElement);

    delete[] dd_in1;
    delete[] dd_in2;
    delete[] gold_out;
    delete[] gdd_in1;
    delete[] gdd_in2;
    delete[] gdd_out;
    delete[] gpu_out;

    FUNC_END_MSG;
}

template<class c_t, class g_t>
void test_mul(const unsigned int numElement) {

    FUNC_START_MSG;

    c_t* dd_in1 = new c_t[numElement];
    c_t* dd_in2 = new c_t[numElement];
    c_t* gold_out = new c_t[numElement];
    c_t low = "-1.0";
    c_t high = "1.0";
    randArray(dd_in1, numElement, low, high, 777);
    randArray(dd_in2, numElement, low, high, 888);

    g_t* gdd_in1 = new g_t[numElement];
    g_t* gdd_in2 = new g_t[numElement];
    g_t* gdd_out = new g_t[numElement];
    qd2gqd(dd_in1, gdd_in1, numElement);
    qd2gqd(dd_in2, gdd_in2, numElement);


    unsigned int numBlock = 128;
    unsigned int numThread = 128;
    device_basic(gdd_in1, gdd_in2, gdd_out, numElement, MUL, numBlock, numThread);
    c_t* gpu_out = new c_t[numElement];
    gqd2qd(gdd_out, gpu_out, numElement);

    INIT_TIMER;
    START_TIMER;
#pragma omp parallel for
    for (unsigned int i = 0; i < numElement; i++) {
        gold_out[i] = dd_in1[i] * dd_in2[i];
    }
    END_TIMER;
    PRINT_TIMER_SEC("CPU mul");

    checkTwoArray(gold_out, gpu_out, numElement);

    delete[] dd_in1;
    delete[] dd_in2;
    delete[] gold_out;
    delete[] gdd_in1;
    delete[] gdd_in2;
    delete[] gdd_out;
    delete[] gpu_out;

    FUNC_END_MSG;
}

template<class c_t, class g_t>
void test_div(const unsigned int numElement) {

    FUNC_START_MSG;

    c_t* dd_in1 = new c_t[numElement];
    c_t* dd_in2 = new c_t[numElement];
    c_t* gold_out = new c_t[numElement];
    c_t low = "-1.0";
    c_t high = "1.0";
    randArray(dd_in1, numElement, low, high, 777);
    randArray(dd_in2, numElement, low, high, 888);
    g_t* gdd_in1 = new g_t[numElement];
    g_t* gdd_in2 = new g_t[numElement];
    g_t* gdd_out = new g_t[numElement];
    qd2gqd(dd_in1, gdd_in1, numElement);
    qd2gqd(dd_in2, gdd_in2, numElement);


    unsigned int numBlock = 128;
    unsigned int numThread = 128;
    device_basic(gdd_in1, gdd_in2, gdd_out, numElement, DIV, numBlock, numThread);
    c_t* gpu_out = new c_t[numElement];
    gqd2qd(gdd_out, gpu_out, numElement);

    INIT_TIMER;
    START_TIMER;
#pragma omp parallel for
    for (unsigned int i = 0; i < numElement; i++) {
        gold_out[i] = dd_in1[i] / dd_in2[i];
    }
    END_TIMER;
    PRINT_TIMER_SEC("CPU div");

    checkTwoArray(gold_out, gpu_out, numElement);

    delete[] dd_in1;
    delete[] dd_in2;
    delete[] gold_out;
    delete[] gdd_in1;
    delete[] gdd_in2;
    delete[] gdd_out;
    delete[] gpu_out;

    FUNC_END_MSG;
}

/*
int main(int argc, char** argv) {
    const int omp_num_thread = 16;
    omp_set_num_threads(omp_num_thread);
    printf("omp_num_thread = %d\n", omp_num_thread);

    unsigned int old_cw;
    fpu_fix_start(&old_cw);



    printf("==================================================================\n");
    printf("******************** double-double precision *********************\n");
    printf("==================================================================\n");
    GDDStart();
    unsigned int numElement = 10000000;
    printf("numElement = %d\n", numElement);
    test_add<dd_real, gdd_real>(numElement);
    test_mul<dd_real, gdd_real>(numElement);
    test_div<dd_real, gdd_real>(numElement);
    test_sqrt<dd_real, gdd_real>(numElement);
    test_exp<dd_real, gdd_real>(numElement);
    test_log<dd_real, gdd_real>(numElement);
    test_sin<dd_real, gdd_real>(numElement);
    test_acos<dd_real, gdd_real>(numElement);
    test_asin<dd_real, gdd_real>(numElement);
    test_tan<dd_real, gdd_real>(numElement);
    GDDEnd();

    printf("\n\n");

    printf("==================================================================\n");
    printf("********************* quad-double precision **********************\n");
    printf("==================================================================\n");
    GQDStart();
    numElement = 1000000;
    printf("numElement = %d\n", numElement);
    test_add<qd_real, gqd_real>(numElement);
    test_mul<qd_real, gqd_real>(numElement);
    test_div<qd_real, gqd_real>(numElement);
    test_sqrt<qd_real, gqd_real>(numElement);
    test_exp<qd_real, gqd_real>(numElement);
    test_log<qd_real, gqd_real>(numElement);
    test_sin<qd_real, gqd_real>(numElement);
    test_tan<qd_real, gqd_real>(numElement);
    GQDEnd();

    fpu_fix_end(&old_cw);
    return EXIT_SUCCESS;
}

*/

enum OP_TYPE {UNARY = 1, BINARY = 2};

template<class GPU_T>
void testFunc(const int numElement, OP_TYPE type, ...) {
	cout << "numElement: " << numElement << endl;
    cout << "op type: " << type << endl;
    va_list vl;

	va_start(vl, type);

	if (UNARY == type) {
		GPU_T a = va_arg(vl, GPU_T);
		cout << "a = " << a << endl;
	} else if(BINARY == type) {
		GPU_T a = va_arg(vl, GPU_T);
		GPU_T b = va_arg(vl, GPU_T);
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
	} else {
		throw std::runtime_error("UNKNOW OP_TYPE");
	}
 
    va_end(vl);
}

template<typename T_R, typename T_A, typename T_B>
T_R op_add(const T_A& a, const T_B& b) {
	return a + b;
}

template<typename T_R, typename T_A>
T_R op_exp(const T_A& a) {
	return exp(a);
}



template<typename T_OUT, typename T_IN1, class OP>
void benchmark(const int numElement, OP op) {
	// Allocate host memory for operands
	T_IN1* h_in1 = new T_IN1[numElement];

	// Generate randome numbers [-1, 1] for the operands on the host
	randArray(h_in1, numElement, -1.0, 1.0);	

	// Copy the input data to the device
	T_IN1* d_in1 = NULL;
	GPUMALLOC((void**)&d_in1, sizeof(T_IN1)*numElement);
	TOGPU(d_in1, h_in1, sizeof(T_IN1)*numElement);

	// Allocate memory for results on the device 
	T_OUT* d_out = NULL;
	GPUMALLOC((void**)&d_out, sizeof(T_OUT)*numElement);

	// Performance computation on device
	cout << "Computation on device done" << endl;

	// Performance computation on host
	cout << "Computation on host done" << endl;
	

	// Memory cleanup
	delete[] h_in1;
	GPUFREE(d_in1);
	GPUFREE(d_out);
}

template<class OP, typename T_R, typename T_IN1, typename T_IN2>
void benchmark(const int numElement, OP op) {

}

int main(int argc, char** argv) {
	const int numElement = 1000000;

	//testFunc<double>(numElement, BINARY, 2.10, 3.10, &op_add<double, double, double>);
	
	//testFunc<int>(numElement, UNARY, 4, &op_exp<double, int>);

	benchmark<gdd_real, gdd_real>(numElement, &op_exp<dd_real, dd_real>);
}



