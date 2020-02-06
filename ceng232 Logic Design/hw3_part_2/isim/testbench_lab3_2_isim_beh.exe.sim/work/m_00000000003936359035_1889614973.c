/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xcb73ee62 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "Time=%t | word=%b selection=%b mode=%b | hips1=%d hips0=%d nerd1=%d nerd0=%d, warning=%b";
static const char *ng1 = "D:/DERS/ceng232/hw/hw3_part_2/testbench_lab3_2.v";
static int ng2[] = {1, 0};
static unsigned int ng3[] = {0U, 0U};
static int ng4[] = {0, 0};
static unsigned int ng5[] = {18U, 0U};
static const char *ng6 = "Test 1: Value of hipsterians1 is wrong";
static const char *ng7 = "Test 1: Value of hipsterians0 is wrong";
static const char *ng8 = "Test 1: Value of nerdians1 is wrong";
static const char *ng9 = "Test 1: Value of nerdians0 is wrong";
static const char *ng10 = "Test 1: Value of warning is wrong";
static const char *ng11 = "Test 1: Successful";
static unsigned int ng12[] = {10U, 0U};
static const char *ng13 = "Test 2: Value of hipsterians1 is wrong";
static const char *ng14 = "Test 2: Value of hipsterians0 is wrong";
static const char *ng15 = "Test 2: Value of nerdians1 is wrong";
static const char *ng16 = "Test 2: Value of nerdians0 is wrong";
static const char *ng17 = "Test 2: Value of warning is wrong";
static const char *ng18 = "Test 2: Successful";
static unsigned int ng19[] = {31U, 0U};
static const char *ng20 = "Test 3: Value of hipsterians1 is wrong";
static const char *ng21 = "Test 3: Value of hipsterians0 is wrong";
static const char *ng22 = "Test 3: Value of nerdians1 is wrong";
static const char *ng23 = "Test 3: Value of nerdians0 is wrong";
static const char *ng24 = "Test 3: Value of warning is wrong";
static const char *ng25 = "Test 3: Successful";
static unsigned int ng26[] = {13U, 0U};
static const char *ng27 = "Test 4: Value of hipsterians1 is wrong";
static const char *ng28 = "Test 4: Value of hipsterians0 is wrong";
static const char *ng29 = "Test 4: Value of nerdians1 is wrong";
static const char *ng30 = "Test 4: Value of nerdians0 is wrong";
static const char *ng31 = "Test 4: Value of warning is wrong";
static const char *ng32 = "Test 4: Successful";
static const char *ng33 = "Test 5: Value of hipsterians1 is wrong";
static const char *ng34 = "Test 5: Value of hipsterians0 is wrong";
static const char *ng35 = "Test 5: Value of nerdians1 is wrong";
static const char *ng36 = "Test 5: Value of nerdians0 is wrong";
static const char *ng37 = "Test 5: Value of warning is wrong";
static const char *ng38 = "Test 5: Successful";
static const char *ng39 = "Test 6: Value of hipsterians1 is wrong";
static const char *ng40 = "Test 6: Value of hipsterians0 is wrong";
static const char *ng41 = "Test 6: Value of nerdians1 is wrong";
static const char *ng42 = "Test 6: Value of nerdians0 is wrong";
static const char *ng43 = "Test 6: Value of warning is wrong";
static const char *ng44 = "Test 6: Successful";
static unsigned int ng45[] = {5U, 0U};
static int ng46[] = {2, 0};
static const char *ng47 = "Test 7: Value of hipsterians1 is wrong";
static const char *ng48 = "Test 7: Value of hipsterians0 is wrong";
static const char *ng49 = "Test 7: Value of nerdians1 is wrong";
static const char *ng50 = "Test 7: Value of nerdians0 is wrong";
static const char *ng51 = "Test 7: Value of warning is wrong";
static const char *ng52 = "Test 7: Successful";
static const char *ng53 = "Test 8: Value of hipsterians1 is wrong";
static const char *ng54 = "Test 8: Value of hipsterians0 is wrong";
static const char *ng55 = "Test 8: Value of nerdians1 is wrong";
static const char *ng56 = "Test 8: Value of nerdians0 is wrong";
static const char *ng57 = "Test 8: Value of warning is wrong";
static const char *ng58 = "Test 8: Successful";
static unsigned int ng59[] = {6U, 0U};
static const char *ng60 = "Test 9: Value of hipsterians1 is wrong";
static const char *ng61 = "Test 9: Value of hipsterians0 is wrong";
static const char *ng62 = "Test 9: Value of nerdians1 is wrong";
static const char *ng63 = "Test 9: Value of nerdians0 is wrong";
static const char *ng64 = "Test 9: Value of warning is wrong";
static const char *ng65 = "Test 9: Successful";
static const char *ng66 = "Test 10: Value of hipsterians1 is wrong";
static int ng67[] = {3, 0};
static const char *ng68 = "Test 10: Value of hipsterians0 is wrong";
static const char *ng69 = "Test 10: Value of nerdians1 is wrong";
static const char *ng70 = "Test 10: Value of nerdians0 is wrong";
static const char *ng71 = "Test 10: Value of warning is wrong";
static const char *ng72 = "Test 10: Successful";

void Monitor_37_3(char *);
void Monitor_37_3(char *);


static void Monitor_37_3_Func(char *t0)
{
    char t1[16];
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;

LAB0:    t2 = xsi_vlog_time(t1, 1000.0000000000000, 1000.0000000000000);
    t3 = (t0 + 1196);
    t4 = (t3 + 36U);
    t5 = *((char **)t4);
    t6 = (t0 + 1380);
    t7 = (t6 + 36U);
    t8 = *((char **)t7);
    t9 = (t0 + 1472);
    t10 = (t9 + 36U);
    t11 = *((char **)t10);
    t12 = (t0 + 600U);
    t13 = *((char **)t12);
    t12 = (t0 + 692U);
    t14 = *((char **)t12);
    t12 = (t0 + 784U);
    t15 = *((char **)t12);
    t12 = (t0 + 876U);
    t16 = *((char **)t12);
    t12 = (t0 + 968U);
    t17 = *((char **)t12);
    xsi_vlogfile_write(1, 0, 3, ng0, 10, t0, (char)118, t1, 64, (char)118, t5, 5, (char)118, t8, 1, (char)118, t11, 1, (char)118, t13, 8, (char)118, t14, 8, (char)118, t15, 8, (char)118, t16, 8, (char)118, t17, 1);

LAB1:    return;
}

static void Initial_32_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(32, ng1);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 1288);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Always_33_1(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 2140U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(33, ng1);
    t2 = (t0 + 2040);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(33, ng1);
    t4 = (t0 + 1288);
    t5 = (t4 + 36U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB8;

LAB6:    if (*((unsigned int *)t7) == 0)
        goto LAB5;

LAB7:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB8:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB10;

LAB9:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 1288);
    xsi_vlogvar_assign_value(t24, t3, 0, 0, 1);
    goto LAB2;

LAB5:    *((unsigned int *)t3) = 1;
    goto LAB8;

LAB10:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB9;

}

static void Initial_35_2(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;

LAB0:    t1 = (t0 + 2284U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(35, ng1);

LAB4:    xsi_set_current_line(37, ng1);
    Monitor_37_3(t0);
    xsi_set_current_line(41, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1196);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(42, ng1);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1380);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(43, ng1);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1472);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(46, ng1);
    t2 = (t0 + 2184);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(54, ng1);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 1196);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(55, ng1);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1380);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(56, ng1);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1472);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(57, ng1);
    t2 = (t0 + 2184);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(58, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB8;

LAB7:    if (t16 != 0)
        goto LAB9;

LAB10:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB11;

LAB12:    xsi_set_current_line(59, ng1);
    t2 = (t0 + 692U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB15;

LAB14:    if (t16 != 0)
        goto LAB16;

LAB17:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(60, ng1);
    t2 = (t0 + 784U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB22;

LAB21:    if (t16 != 0)
        goto LAB23;

LAB24:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB25;

LAB26:    xsi_set_current_line(61, ng1);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB29;

LAB28:    if (t16 != 0)
        goto LAB30;

LAB31:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB32;

LAB33:    xsi_set_current_line(62, ng1);
    t2 = (t0 + 968U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB36;

LAB35:    if (t16 != 0)
        goto LAB37;

LAB38:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB39;

LAB40:    xsi_set_current_line(63, ng1);
    xsi_vlogfile_write(1, 0, 0, ng11, 1, t0);

LAB41:
LAB34:
LAB27:
LAB20:
LAB13:    xsi_set_current_line(68, ng1);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1196);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(69, ng1);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1380);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(70, ng1);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1472);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(71, ng1);
    t2 = (t0 + 2184);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB42;
    goto LAB1;

LAB8:    *((unsigned int *)t4) = 1;
    goto LAB10;

LAB9:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB10;

LAB11:    xsi_set_current_line(58, ng1);
    xsi_vlogfile_write(1, 0, 0, ng6, 1, t0);
    goto LAB13;

LAB15:    *((unsigned int *)t4) = 1;
    goto LAB17;

LAB16:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB17;

LAB18:    xsi_set_current_line(59, ng1);
    xsi_vlogfile_write(1, 0, 0, ng7, 1, t0);
    goto LAB20;

LAB22:    *((unsigned int *)t4) = 1;
    goto LAB24;

LAB23:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB24;

LAB25:    xsi_set_current_line(60, ng1);
    xsi_vlogfile_write(1, 0, 0, ng8, 1, t0);
    goto LAB27;

LAB29:    *((unsigned int *)t4) = 1;
    goto LAB31;

LAB30:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB31;

LAB32:    xsi_set_current_line(61, ng1);
    xsi_vlogfile_write(1, 0, 0, ng9, 1, t0);
    goto LAB34;

LAB36:    *((unsigned int *)t4) = 1;
    goto LAB38;

LAB37:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB38;

LAB39:    xsi_set_current_line(62, ng1);
    xsi_vlogfile_write(1, 0, 0, ng10, 1, t0);
    goto LAB41;

LAB42:    xsi_set_current_line(72, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB44;

LAB43:    if (t16 != 0)
        goto LAB45;

LAB46:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB47;

LAB48:    xsi_set_current_line(73, ng1);
    t2 = (t0 + 692U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB51;

LAB50:    if (t16 != 0)
        goto LAB52;

LAB53:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB54;

LAB55:    xsi_set_current_line(74, ng1);
    t2 = (t0 + 784U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB58;

LAB57:    if (t16 != 0)
        goto LAB59;

LAB60:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB61;

LAB62:    xsi_set_current_line(75, ng1);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB65;

LAB64:    if (t16 != 0)
        goto LAB66;

LAB67:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB68;

LAB69:    xsi_set_current_line(76, ng1);
    t2 = (t0 + 968U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB72;

LAB71:    if (t16 != 0)
        goto LAB73;

LAB74:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB75;

LAB76:    xsi_set_current_line(77, ng1);
    xsi_vlogfile_write(1, 0, 0, ng18, 1, t0);

LAB77:
LAB70:
LAB63:
LAB56:
LAB49:    xsi_set_current_line(82, ng1);
    t2 = ((char*)((ng19)));
    t3 = (t0 + 1196);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(83, ng1);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1380);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(84, ng1);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1472);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(85, ng1);
    t2 = (t0 + 2184);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB78;
    goto LAB1;

LAB44:    *((unsigned int *)t4) = 1;
    goto LAB46;

LAB45:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB46;

LAB47:    xsi_set_current_line(72, ng1);
    xsi_vlogfile_write(1, 0, 0, ng13, 1, t0);
    goto LAB49;

LAB51:    *((unsigned int *)t4) = 1;
    goto LAB53;

LAB52:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB53;

LAB54:    xsi_set_current_line(73, ng1);
    xsi_vlogfile_write(1, 0, 0, ng14, 1, t0);
    goto LAB56;

LAB58:    *((unsigned int *)t4) = 1;
    goto LAB60;

LAB59:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB60;

LAB61:    xsi_set_current_line(74, ng1);
    xsi_vlogfile_write(1, 0, 0, ng15, 1, t0);
    goto LAB63;

LAB65:    *((unsigned int *)t4) = 1;
    goto LAB67;

LAB66:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB67;

LAB68:    xsi_set_current_line(75, ng1);
    xsi_vlogfile_write(1, 0, 0, ng16, 1, t0);
    goto LAB70;

LAB72:    *((unsigned int *)t4) = 1;
    goto LAB74;

LAB73:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB74;

LAB75:    xsi_set_current_line(76, ng1);
    xsi_vlogfile_write(1, 0, 0, ng17, 1, t0);
    goto LAB77;

LAB78:    xsi_set_current_line(86, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB80;

LAB79:    if (t16 != 0)
        goto LAB81;

LAB82:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB83;

LAB84:    xsi_set_current_line(87, ng1);
    t2 = (t0 + 692U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB87;

LAB86:    if (t16 != 0)
        goto LAB88;

LAB89:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB90;

LAB91:    xsi_set_current_line(88, ng1);
    t2 = (t0 + 784U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB94;

LAB93:    if (t16 != 0)
        goto LAB95;

LAB96:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB97;

LAB98:    xsi_set_current_line(89, ng1);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB101;

LAB100:    if (t16 != 0)
        goto LAB102;

LAB103:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB104;

LAB105:    xsi_set_current_line(90, ng1);
    t2 = (t0 + 968U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB108;

LAB107:    if (t16 != 0)
        goto LAB109;

LAB110:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB111;

LAB112:    xsi_set_current_line(91, ng1);
    xsi_vlogfile_write(1, 0, 0, ng25, 1, t0);

LAB113:
LAB106:
LAB99:
LAB92:
LAB85:    xsi_set_current_line(96, ng1);
    t2 = ((char*)((ng26)));
    t3 = (t0 + 1196);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(97, ng1);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1380);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(98, ng1);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1472);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(99, ng1);
    t2 = (t0 + 2184);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB114;
    goto LAB1;

LAB80:    *((unsigned int *)t4) = 1;
    goto LAB82;

LAB81:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB82;

LAB83:    xsi_set_current_line(86, ng1);
    xsi_vlogfile_write(1, 0, 0, ng20, 1, t0);
    goto LAB85;

LAB87:    *((unsigned int *)t4) = 1;
    goto LAB89;

LAB88:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB89;

LAB90:    xsi_set_current_line(87, ng1);
    xsi_vlogfile_write(1, 0, 0, ng21, 1, t0);
    goto LAB92;

LAB94:    *((unsigned int *)t4) = 1;
    goto LAB96;

LAB95:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB96;

LAB97:    xsi_set_current_line(88, ng1);
    xsi_vlogfile_write(1, 0, 0, ng22, 1, t0);
    goto LAB99;

LAB101:    *((unsigned int *)t4) = 1;
    goto LAB103;

LAB102:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB103;

LAB104:    xsi_set_current_line(89, ng1);
    xsi_vlogfile_write(1, 0, 0, ng23, 1, t0);
    goto LAB106;

LAB108:    *((unsigned int *)t4) = 1;
    goto LAB110;

LAB109:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB110;

LAB111:    xsi_set_current_line(90, ng1);
    xsi_vlogfile_write(1, 0, 0, ng24, 1, t0);
    goto LAB113;

LAB114:    xsi_set_current_line(100, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB116;

LAB115:    if (t16 != 0)
        goto LAB117;

LAB118:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB119;

LAB120:    xsi_set_current_line(101, ng1);
    t2 = (t0 + 692U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB123;

LAB122:    if (t16 != 0)
        goto LAB124;

LAB125:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB126;

LAB127:    xsi_set_current_line(102, ng1);
    t2 = (t0 + 784U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB130;

LAB129:    if (t16 != 0)
        goto LAB131;

LAB132:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB133;

LAB134:    xsi_set_current_line(103, ng1);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB137;

LAB136:    if (t16 != 0)
        goto LAB138;

LAB139:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB140;

LAB141:    xsi_set_current_line(104, ng1);
    t2 = (t0 + 968U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB144;

LAB143:    if (t16 != 0)
        goto LAB145;

LAB146:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB147;

LAB148:    xsi_set_current_line(105, ng1);
    xsi_vlogfile_write(1, 0, 0, ng32, 1, t0);

LAB149:
LAB142:
LAB135:
LAB128:
LAB121:    xsi_set_current_line(110, ng1);
    t2 = ((char*)((ng26)));
    t3 = (t0 + 1196);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(111, ng1);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1380);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(112, ng1);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1472);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(113, ng1);
    t2 = (t0 + 2184);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB150;
    goto LAB1;

LAB116:    *((unsigned int *)t4) = 1;
    goto LAB118;

LAB117:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB118;

LAB119:    xsi_set_current_line(100, ng1);
    xsi_vlogfile_write(1, 0, 0, ng27, 1, t0);
    goto LAB121;

LAB123:    *((unsigned int *)t4) = 1;
    goto LAB125;

LAB124:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB125;

LAB126:    xsi_set_current_line(101, ng1);
    xsi_vlogfile_write(1, 0, 0, ng28, 1, t0);
    goto LAB128;

LAB130:    *((unsigned int *)t4) = 1;
    goto LAB132;

LAB131:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB132;

LAB133:    xsi_set_current_line(102, ng1);
    xsi_vlogfile_write(1, 0, 0, ng29, 1, t0);
    goto LAB135;

LAB137:    *((unsigned int *)t4) = 1;
    goto LAB139;

LAB138:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB139;

LAB140:    xsi_set_current_line(103, ng1);
    xsi_vlogfile_write(1, 0, 0, ng30, 1, t0);
    goto LAB142;

LAB144:    *((unsigned int *)t4) = 1;
    goto LAB146;

LAB145:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB146;

LAB147:    xsi_set_current_line(104, ng1);
    xsi_vlogfile_write(1, 0, 0, ng31, 1, t0);
    goto LAB149;

LAB150:    xsi_set_current_line(114, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB152;

LAB151:    if (t16 != 0)
        goto LAB153;

LAB154:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB155;

LAB156:    xsi_set_current_line(115, ng1);
    t2 = (t0 + 692U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB159;

LAB158:    if (t16 != 0)
        goto LAB160;

LAB161:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB162;

LAB163:    xsi_set_current_line(116, ng1);
    t2 = (t0 + 784U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB166;

LAB165:    if (t16 != 0)
        goto LAB167;

LAB168:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB169;

LAB170:    xsi_set_current_line(117, ng1);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB173;

LAB172:    if (t16 != 0)
        goto LAB174;

LAB175:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB176;

LAB177:    xsi_set_current_line(118, ng1);
    t2 = (t0 + 968U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB180;

LAB179:    if (t16 != 0)
        goto LAB181;

LAB182:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB183;

LAB184:    xsi_set_current_line(119, ng1);
    xsi_vlogfile_write(1, 0, 0, ng38, 1, t0);

LAB185:
LAB178:
LAB171:
LAB164:
LAB157:    xsi_set_current_line(124, ng1);
    t2 = ((char*)((ng26)));
    t3 = (t0 + 1196);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(125, ng1);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1380);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(126, ng1);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1472);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(127, ng1);
    t2 = (t0 + 2184);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB186;
    goto LAB1;

LAB152:    *((unsigned int *)t4) = 1;
    goto LAB154;

LAB153:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB154;

LAB155:    xsi_set_current_line(114, ng1);
    xsi_vlogfile_write(1, 0, 0, ng33, 1, t0);
    goto LAB157;

LAB159:    *((unsigned int *)t4) = 1;
    goto LAB161;

LAB160:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB161;

LAB162:    xsi_set_current_line(115, ng1);
    xsi_vlogfile_write(1, 0, 0, ng34, 1, t0);
    goto LAB164;

LAB166:    *((unsigned int *)t4) = 1;
    goto LAB168;

LAB167:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB168;

LAB169:    xsi_set_current_line(116, ng1);
    xsi_vlogfile_write(1, 0, 0, ng35, 1, t0);
    goto LAB171;

LAB173:    *((unsigned int *)t4) = 1;
    goto LAB175;

LAB174:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB175;

LAB176:    xsi_set_current_line(117, ng1);
    xsi_vlogfile_write(1, 0, 0, ng36, 1, t0);
    goto LAB178;

LAB180:    *((unsigned int *)t4) = 1;
    goto LAB182;

LAB181:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB182;

LAB183:    xsi_set_current_line(118, ng1);
    xsi_vlogfile_write(1, 0, 0, ng37, 1, t0);
    goto LAB185;

LAB186:    xsi_set_current_line(128, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB188;

LAB187:    if (t16 != 0)
        goto LAB189;

LAB190:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB191;

LAB192:    xsi_set_current_line(129, ng1);
    t2 = (t0 + 692U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB195;

LAB194:    if (t16 != 0)
        goto LAB196;

LAB197:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB198;

LAB199:    xsi_set_current_line(130, ng1);
    t2 = (t0 + 784U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB202;

LAB201:    if (t16 != 0)
        goto LAB203;

LAB204:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB205;

LAB206:    xsi_set_current_line(131, ng1);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB209;

LAB208:    if (t16 != 0)
        goto LAB210;

LAB211:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB212;

LAB213:    xsi_set_current_line(132, ng1);
    t2 = (t0 + 968U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB216;

LAB215:    if (t16 != 0)
        goto LAB217;

LAB218:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB219;

LAB220:    xsi_set_current_line(133, ng1);
    xsi_vlogfile_write(1, 0, 0, ng44, 1, t0);

LAB221:
LAB214:
LAB207:
LAB200:
LAB193:    xsi_set_current_line(138, ng1);
    t2 = ((char*)((ng45)));
    t3 = (t0 + 1196);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(139, ng1);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1380);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(140, ng1);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1472);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(141, ng1);
    t2 = (t0 + 2184);
    xsi_process_wait(t2, 190000LL);
    *((char **)t1) = &&LAB222;
    goto LAB1;

LAB188:    *((unsigned int *)t4) = 1;
    goto LAB190;

LAB189:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB190;

LAB191:    xsi_set_current_line(128, ng1);
    xsi_vlogfile_write(1, 0, 0, ng39, 1, t0);
    goto LAB193;

LAB195:    *((unsigned int *)t4) = 1;
    goto LAB197;

LAB196:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB197;

LAB198:    xsi_set_current_line(129, ng1);
    xsi_vlogfile_write(1, 0, 0, ng40, 1, t0);
    goto LAB200;

LAB202:    *((unsigned int *)t4) = 1;
    goto LAB204;

LAB203:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB204;

LAB205:    xsi_set_current_line(130, ng1);
    xsi_vlogfile_write(1, 0, 0, ng41, 1, t0);
    goto LAB207;

LAB209:    *((unsigned int *)t4) = 1;
    goto LAB211;

LAB210:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB211;

LAB212:    xsi_set_current_line(131, ng1);
    xsi_vlogfile_write(1, 0, 0, ng42, 1, t0);
    goto LAB214;

LAB216:    *((unsigned int *)t4) = 1;
    goto LAB218;

LAB217:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB218;

LAB219:    xsi_set_current_line(132, ng1);
    xsi_vlogfile_write(1, 0, 0, ng43, 1, t0);
    goto LAB221;

LAB222:    xsi_set_current_line(142, ng1);
    t3 = (t0 + 600U);
    t5 = *((char **)t3);
    t3 = ((char*)((ng46)));
    memset(t4, 0, 8);
    t6 = (t5 + 4);
    t19 = (t3 + 4);
    t7 = *((unsigned int *)t5);
    t8 = *((unsigned int *)t3);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t6);
    t11 = *((unsigned int *)t19);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t19);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB224;

LAB223:    if (t16 != 0)
        goto LAB225;

LAB226:    t26 = (t4 + 4);
    t21 = *((unsigned int *)t26);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB227;

LAB228:    xsi_set_current_line(143, ng1);
    t2 = (t0 + 692U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB231;

LAB230:    if (t16 != 0)
        goto LAB232;

LAB233:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB234;

LAB235:    xsi_set_current_line(144, ng1);
    t2 = (t0 + 784U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB238;

LAB237:    if (t16 != 0)
        goto LAB239;

LAB240:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB241;

LAB242:    xsi_set_current_line(145, ng1);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB245;

LAB244:    if (t16 != 0)
        goto LAB246;

LAB247:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB248;

LAB249:    xsi_set_current_line(146, ng1);
    t2 = (t0 + 968U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB252;

LAB251:    if (t16 != 0)
        goto LAB253;

LAB254:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB255;

LAB256:    xsi_set_current_line(147, ng1);
    xsi_vlogfile_write(1, 0, 0, ng52, 1, t0);

LAB257:
LAB250:
LAB243:
LAB236:
LAB229:    xsi_set_current_line(152, ng1);
    t2 = ((char*)((ng45)));
    t3 = (t0 + 1196);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(153, ng1);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1380);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(154, ng1);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1472);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(155, ng1);
    t2 = (t0 + 2184);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB258;
    goto LAB1;

LAB224:    *((unsigned int *)t4) = 1;
    goto LAB226;

LAB225:    t20 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB226;

LAB227:    xsi_set_current_line(142, ng1);
    xsi_vlogfile_write(1, 0, 0, ng47, 1, t0);
    goto LAB229;

LAB231:    *((unsigned int *)t4) = 1;
    goto LAB233;

LAB232:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB233;

LAB234:    xsi_set_current_line(143, ng1);
    xsi_vlogfile_write(1, 0, 0, ng48, 1, t0);
    goto LAB236;

LAB238:    *((unsigned int *)t4) = 1;
    goto LAB240;

LAB239:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB240;

LAB241:    xsi_set_current_line(144, ng1);
    xsi_vlogfile_write(1, 0, 0, ng49, 1, t0);
    goto LAB243;

LAB245:    *((unsigned int *)t4) = 1;
    goto LAB247;

LAB246:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB247;

LAB248:    xsi_set_current_line(145, ng1);
    xsi_vlogfile_write(1, 0, 0, ng50, 1, t0);
    goto LAB250;

LAB252:    *((unsigned int *)t4) = 1;
    goto LAB254;

LAB253:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB254;

LAB255:    xsi_set_current_line(146, ng1);
    xsi_vlogfile_write(1, 0, 0, ng51, 1, t0);
    goto LAB257;

LAB258:    xsi_set_current_line(156, ng1);
    t3 = (t0 + 600U);
    t5 = *((char **)t3);
    t3 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t6 = (t5 + 4);
    t19 = (t3 + 4);
    t7 = *((unsigned int *)t5);
    t8 = *((unsigned int *)t3);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t6);
    t11 = *((unsigned int *)t19);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t19);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB260;

LAB259:    if (t16 != 0)
        goto LAB261;

LAB262:    t26 = (t4 + 4);
    t21 = *((unsigned int *)t26);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB263;

LAB264:    xsi_set_current_line(157, ng1);
    t2 = (t0 + 692U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB267;

LAB266:    if (t16 != 0)
        goto LAB268;

LAB269:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB270;

LAB271:    xsi_set_current_line(158, ng1);
    t2 = (t0 + 784U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB274;

LAB273:    if (t16 != 0)
        goto LAB275;

LAB276:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB277;

LAB278:    xsi_set_current_line(159, ng1);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB281;

LAB280:    if (t16 != 0)
        goto LAB282;

LAB283:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB284;

LAB285:    xsi_set_current_line(160, ng1);
    t2 = (t0 + 968U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB288;

LAB287:    if (t16 != 0)
        goto LAB289;

LAB290:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB291;

LAB292:    xsi_set_current_line(161, ng1);
    xsi_vlogfile_write(1, 0, 0, ng58, 1, t0);

LAB293:
LAB286:
LAB279:
LAB272:
LAB265:    xsi_set_current_line(166, ng1);
    t2 = ((char*)((ng59)));
    t3 = (t0 + 1196);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(167, ng1);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1380);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(168, ng1);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1472);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(169, ng1);
    t2 = (t0 + 2184);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB294;
    goto LAB1;

LAB260:    *((unsigned int *)t4) = 1;
    goto LAB262;

LAB261:    t20 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB262;

LAB263:    xsi_set_current_line(156, ng1);
    xsi_vlogfile_write(1, 0, 0, ng53, 1, t0);
    goto LAB265;

LAB267:    *((unsigned int *)t4) = 1;
    goto LAB269;

LAB268:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB269;

LAB270:    xsi_set_current_line(157, ng1);
    xsi_vlogfile_write(1, 0, 0, ng54, 1, t0);
    goto LAB272;

LAB274:    *((unsigned int *)t4) = 1;
    goto LAB276;

LAB275:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB276;

LAB277:    xsi_set_current_line(158, ng1);
    xsi_vlogfile_write(1, 0, 0, ng55, 1, t0);
    goto LAB279;

LAB281:    *((unsigned int *)t4) = 1;
    goto LAB283;

LAB282:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB283;

LAB284:    xsi_set_current_line(159, ng1);
    xsi_vlogfile_write(1, 0, 0, ng56, 1, t0);
    goto LAB286;

LAB288:    *((unsigned int *)t4) = 1;
    goto LAB290;

LAB289:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB290;

LAB291:    xsi_set_current_line(160, ng1);
    xsi_vlogfile_write(1, 0, 0, ng57, 1, t0);
    goto LAB293;

LAB294:    xsi_set_current_line(170, ng1);
    t3 = (t0 + 600U);
    t5 = *((char **)t3);
    t3 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t6 = (t5 + 4);
    t19 = (t3 + 4);
    t7 = *((unsigned int *)t5);
    t8 = *((unsigned int *)t3);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t6);
    t11 = *((unsigned int *)t19);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t19);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB296;

LAB295:    if (t16 != 0)
        goto LAB297;

LAB298:    t26 = (t4 + 4);
    t21 = *((unsigned int *)t26);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB299;

LAB300:    xsi_set_current_line(171, ng1);
    t2 = (t0 + 692U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB303;

LAB302:    if (t16 != 0)
        goto LAB304;

LAB305:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB306;

LAB307:    xsi_set_current_line(172, ng1);
    t2 = (t0 + 784U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB310;

LAB309:    if (t16 != 0)
        goto LAB311;

LAB312:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB313;

LAB314:    xsi_set_current_line(173, ng1);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB317;

LAB316:    if (t16 != 0)
        goto LAB318;

LAB319:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB320;

LAB321:    xsi_set_current_line(174, ng1);
    t2 = (t0 + 968U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB324;

LAB323:    if (t16 != 0)
        goto LAB325;

LAB326:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB327;

LAB328:    xsi_set_current_line(175, ng1);
    xsi_vlogfile_write(1, 0, 0, ng65, 1, t0);

LAB329:
LAB322:
LAB315:
LAB308:
LAB301:    xsi_set_current_line(180, ng1);
    t2 = ((char*)((ng59)));
    t3 = (t0 + 1196);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(181, ng1);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1380);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(182, ng1);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1472);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(183, ng1);
    t2 = (t0 + 2184);
    xsi_process_wait(t2, 150000LL);
    *((char **)t1) = &&LAB330;
    goto LAB1;

LAB296:    *((unsigned int *)t4) = 1;
    goto LAB298;

LAB297:    t20 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB298;

LAB299:    xsi_set_current_line(170, ng1);
    xsi_vlogfile_write(1, 0, 0, ng60, 1, t0);
    goto LAB301;

LAB303:    *((unsigned int *)t4) = 1;
    goto LAB305;

LAB304:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB305;

LAB306:    xsi_set_current_line(171, ng1);
    xsi_vlogfile_write(1, 0, 0, ng61, 1, t0);
    goto LAB308;

LAB310:    *((unsigned int *)t4) = 1;
    goto LAB312;

LAB311:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB312;

LAB313:    xsi_set_current_line(172, ng1);
    xsi_vlogfile_write(1, 0, 0, ng62, 1, t0);
    goto LAB315;

LAB317:    *((unsigned int *)t4) = 1;
    goto LAB319;

LAB318:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB319;

LAB320:    xsi_set_current_line(173, ng1);
    xsi_vlogfile_write(1, 0, 0, ng63, 1, t0);
    goto LAB322;

LAB324:    *((unsigned int *)t4) = 1;
    goto LAB326;

LAB325:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB326;

LAB327:    xsi_set_current_line(174, ng1);
    xsi_vlogfile_write(1, 0, 0, ng64, 1, t0);
    goto LAB329;

LAB330:    xsi_set_current_line(184, ng1);
    t3 = ((char*)((ng4)));
    t5 = (t0 + 1472);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 1);
    xsi_set_current_line(185, ng1);
    t2 = (t0 + 2184);
    xsi_process_wait(t2, 20000LL);
    *((char **)t1) = &&LAB331;
    goto LAB1;

LAB331:    xsi_set_current_line(186, ng1);
    t3 = (t0 + 600U);
    t5 = *((char **)t3);
    t3 = ((char*)((ng2)));
    memset(t4, 0, 8);
    t6 = (t5 + 4);
    t19 = (t3 + 4);
    t7 = *((unsigned int *)t5);
    t8 = *((unsigned int *)t3);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t6);
    t11 = *((unsigned int *)t19);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t19);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB333;

LAB332:    if (t16 != 0)
        goto LAB334;

LAB335:    t26 = (t4 + 4);
    t21 = *((unsigned int *)t26);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB336;

LAB337:    xsi_set_current_line(187, ng1);
    t2 = (t0 + 692U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng67)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB340;

LAB339:    if (t16 != 0)
        goto LAB341;

LAB342:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB343;

LAB344:    xsi_set_current_line(188, ng1);
    t2 = (t0 + 784U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB347;

LAB346:    if (t16 != 0)
        goto LAB348;

LAB349:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB350;

LAB351:    xsi_set_current_line(189, ng1);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB354;

LAB353:    if (t16 != 0)
        goto LAB355;

LAB356:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB357;

LAB358:    xsi_set_current_line(190, ng1);
    t2 = (t0 + 968U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB361;

LAB360:    if (t16 != 0)
        goto LAB362;

LAB363:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB364;

LAB365:    xsi_set_current_line(191, ng1);
    xsi_vlogfile_write(1, 0, 0, ng72, 1, t0);

LAB366:
LAB359:
LAB352:
LAB345:
LAB338:    xsi_set_current_line(193, ng1);
    xsi_vlog_finish(1);
    goto LAB1;

LAB333:    *((unsigned int *)t4) = 1;
    goto LAB335;

LAB334:    t20 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t20) = 1;
    goto LAB335;

LAB336:    xsi_set_current_line(186, ng1);
    xsi_vlogfile_write(1, 0, 0, ng66, 1, t0);
    goto LAB338;

LAB340:    *((unsigned int *)t4) = 1;
    goto LAB342;

LAB341:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB342;

LAB343:    xsi_set_current_line(187, ng1);
    xsi_vlogfile_write(1, 0, 0, ng68, 1, t0);
    goto LAB345;

LAB347:    *((unsigned int *)t4) = 1;
    goto LAB349;

LAB348:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB349;

LAB350:    xsi_set_current_line(188, ng1);
    xsi_vlogfile_write(1, 0, 0, ng69, 1, t0);
    goto LAB352;

LAB354:    *((unsigned int *)t4) = 1;
    goto LAB356;

LAB355:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB356;

LAB357:    xsi_set_current_line(189, ng1);
    xsi_vlogfile_write(1, 0, 0, ng70, 1, t0);
    goto LAB359;

LAB361:    *((unsigned int *)t4) = 1;
    goto LAB363;

LAB362:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB363;

LAB364:    xsi_set_current_line(190, ng1);
    xsi_vlogfile_write(1, 0, 0, ng71, 1, t0);
    goto LAB366;

}

void Monitor_37_3(char *t0)
{
    char *t1;
    char *t2;

LAB0:    t1 = (t0 + 2328);
    t2 = (t0 + 2624);
    xsi_vlogfile_monitor((void *)Monitor_37_3_Func, t1, t2);

LAB1:    return;
}


extern void work_m_00000000003936359035_1889614973_init()
{
	static char *pe[] = {(void *)Initial_32_0,(void *)Always_33_1,(void *)Initial_35_2,(void *)Monitor_37_3};
	xsi_register_didat("work_m_00000000003936359035_1889614973", "isim/testbench_lab3_2_isim_beh.exe.sim/work/m_00000000003936359035_1889614973.didat");
	xsi_register_executes(pe);
}
