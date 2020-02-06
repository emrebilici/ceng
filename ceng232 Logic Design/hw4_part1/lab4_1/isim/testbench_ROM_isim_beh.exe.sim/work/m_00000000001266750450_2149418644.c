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
static const char *ng0 = "D:/DERS/ceng232/hw/hw4_part1/lab4_1/testbench_ROM.v";
static const char *ng1 = "Starting Testbench";
static unsigned int ng2[] = {0U, 0U};
static int ng3[] = {1, 0};
static const char *ng4 = "time:";
static const char *ng5 = ":For romAddress:%b Error in romData:%b";
static unsigned int ng6[] = {1U, 0U};
static unsigned int ng7[] = {2U, 0U};
static unsigned int ng8[] = {4U, 0U};
static unsigned int ng9[] = {15U, 0U};
static unsigned int ng10[] = {31U, 0U};
static const char *ng11 = "Result %d";
static const char *ng12 = "Testbench was finished";



static void Initial_11_0(char *t0)
{
    char t4[8];
    char t30[8];
    char t32[16];
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
    char *t27;
    char *t28;
    char *t29;
    char *t31;

LAB0:    t1 = (t0 + 1444U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(11, ng0);

LAB4:    xsi_set_current_line(13, ng0);
    xsi_vlogfile_write(1, 0, 0, ng1, 1, t0);
    xsi_set_current_line(16, ng0);
    t2 = (t0 + 1344);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(17, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(18, ng0);
    t2 = (t0 + 1344);
    xsi_process_wait(t2, 7000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(19, ng0);
    t2 = (t0 + 600U);
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
        goto LAB10;

LAB7:    if (t16 != 0)
        goto LAB9;

LAB8:    *((unsigned int *)t4) = 1;

LAB10:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB11;

LAB12:    xsi_set_current_line(20, ng0);
    t2 = xsi_vlog_time(t32, 1000.0000000000000, 1000.0000000000000);
    xsi_vlogfile_write(0, 0, 0, ng4, 2, t0, (char)118, t32, 64);
    t3 = (t0 + 828);
    t5 = (t3 + 36U);
    t6 = *((char **)t5);
    t19 = (t0 + 600U);
    t20 = *((char **)t19);
    xsi_vlogfile_write(1, 0, 0, ng5, 3, t0, (char)118, t6, 4, (char)118, t20, 5);

LAB13:    xsi_set_current_line(22, ng0);
    t2 = (t0 + 1344);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB14;
    goto LAB1;

LAB9:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB10;

LAB11:    xsi_set_current_line(19, ng0);
    t26 = (t0 + 920);
    t27 = (t26 + 36U);
    t28 = *((char **)t27);
    t29 = ((char*)((ng3)));
    memset(t30, 0, 8);
    xsi_vlog_signed_add(t30, 32, t28, 32, t29, 32);
    t31 = (t0 + 920);
    xsi_vlogvar_assign_value(t31, t30, 0, 0, 32);
    goto LAB13;

LAB14:    xsi_set_current_line(24, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(25, ng0);
    t2 = (t0 + 1344);
    xsi_process_wait(t2, 7000LL);
    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB15:    xsi_set_current_line(26, ng0);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng7)));
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
        goto LAB19;

LAB16:    if (t16 != 0)
        goto LAB18;

LAB17:    *((unsigned int *)t4) = 1;

LAB19:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB20;

LAB21:    xsi_set_current_line(27, ng0);
    t2 = xsi_vlog_time(t32, 1000.0000000000000, 1000.0000000000000);
    xsi_vlogfile_write(0, 0, 0, ng4, 2, t0, (char)118, t32, 64);
    t3 = (t0 + 828);
    t5 = (t3 + 36U);
    t6 = *((char **)t5);
    t19 = (t0 + 600U);
    t20 = *((char **)t19);
    xsi_vlogfile_write(1, 0, 0, ng5, 3, t0, (char)118, t6, 4, (char)118, t20, 5);

LAB22:    xsi_set_current_line(29, ng0);
    t2 = (t0 + 1344);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB23;
    goto LAB1;

LAB18:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB19;

LAB20:    xsi_set_current_line(26, ng0);
    t26 = (t0 + 920);
    t27 = (t26 + 36U);
    t28 = *((char **)t27);
    t29 = ((char*)((ng3)));
    memset(t30, 0, 8);
    xsi_vlog_signed_add(t30, 32, t28, 32, t29, 32);
    t31 = (t0 + 920);
    xsi_vlogvar_assign_value(t31, t30, 0, 0, 32);
    goto LAB22;

LAB23:    xsi_set_current_line(31, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(32, ng0);
    t2 = (t0 + 1344);
    xsi_process_wait(t2, 7000LL);
    *((char **)t1) = &&LAB24;
    goto LAB1;

LAB24:    xsi_set_current_line(33, ng0);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng8)));
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
        goto LAB28;

LAB25:    if (t16 != 0)
        goto LAB27;

LAB26:    *((unsigned int *)t4) = 1;

LAB28:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB29;

LAB30:    xsi_set_current_line(34, ng0);
    t2 = xsi_vlog_time(t32, 1000.0000000000000, 1000.0000000000000);
    xsi_vlogfile_write(0, 0, 0, ng4, 2, t0, (char)118, t32, 64);
    t3 = (t0 + 828);
    t5 = (t3 + 36U);
    t6 = *((char **)t5);
    t19 = (t0 + 600U);
    t20 = *((char **)t19);
    xsi_vlogfile_write(1, 0, 0, ng5, 3, t0, (char)118, t6, 4, (char)118, t20, 5);

LAB31:    xsi_set_current_line(36, ng0);
    t2 = (t0 + 1344);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB32;
    goto LAB1;

LAB27:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB28;

LAB29:    xsi_set_current_line(33, ng0);
    t26 = (t0 + 920);
    t27 = (t26 + 36U);
    t28 = *((char **)t27);
    t29 = ((char*)((ng3)));
    memset(t30, 0, 8);
    xsi_vlog_signed_add(t30, 32, t28, 32, t29, 32);
    t31 = (t0 + 920);
    xsi_vlogvar_assign_value(t31, t30, 0, 0, 32);
    goto LAB31;

LAB32:    xsi_set_current_line(37, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(38, ng0);
    t2 = (t0 + 1344);
    xsi_process_wait(t2, 7000LL);
    *((char **)t1) = &&LAB33;
    goto LAB1;

LAB33:    xsi_set_current_line(39, ng0);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng10)));
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
        goto LAB37;

LAB34:    if (t16 != 0)
        goto LAB36;

LAB35:    *((unsigned int *)t4) = 1;

LAB37:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB38;

LAB39:    xsi_set_current_line(40, ng0);
    t2 = xsi_vlog_time(t32, 1000.0000000000000, 1000.0000000000000);
    xsi_vlogfile_write(0, 0, 0, ng4, 2, t0, (char)118, t32, 64);
    t3 = (t0 + 828);
    t5 = (t3 + 36U);
    t6 = *((char **)t5);
    t19 = (t0 + 600U);
    t20 = *((char **)t19);
    xsi_vlogfile_write(1, 0, 0, ng5, 3, t0, (char)118, t6, 4, (char)118, t20, 5);

LAB40:    xsi_set_current_line(42, ng0);
    t2 = (t0 + 1344);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB41;
    goto LAB1;

LAB36:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB37;

LAB38:    xsi_set_current_line(39, ng0);
    t26 = (t0 + 920);
    t27 = (t26 + 36U);
    t28 = *((char **)t27);
    t29 = ((char*)((ng3)));
    memset(t30, 0, 8);
    xsi_vlog_signed_add(t30, 32, t28, 32, t29, 32);
    t31 = (t0 + 920);
    xsi_vlogvar_assign_value(t31, t30, 0, 0, 32);
    goto LAB40;

LAB41:    xsi_set_current_line(43, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(44, ng0);
    t2 = (t0 + 1344);
    xsi_process_wait(t2, 7000LL);
    *((char **)t1) = &&LAB42;
    goto LAB1;

LAB42:    xsi_set_current_line(45, ng0);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng7)));
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
        goto LAB46;

LAB43:    if (t16 != 0)
        goto LAB45;

LAB44:    *((unsigned int *)t4) = 1;

LAB46:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB47;

LAB48:    xsi_set_current_line(46, ng0);
    t2 = xsi_vlog_time(t32, 1000.0000000000000, 1000.0000000000000);
    xsi_vlogfile_write(0, 0, 0, ng4, 2, t0, (char)118, t32, 64);
    t3 = (t0 + 828);
    t5 = (t3 + 36U);
    t6 = *((char **)t5);
    t19 = (t0 + 600U);
    t20 = *((char **)t19);
    xsi_vlogfile_write(1, 0, 0, ng5, 3, t0, (char)118, t6, 4, (char)118, t20, 5);

LAB49:    xsi_set_current_line(48, ng0);
    t2 = (t0 + 1344);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB50;
    goto LAB1;

LAB45:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB46;

LAB47:    xsi_set_current_line(45, ng0);
    t26 = (t0 + 920);
    t27 = (t26 + 36U);
    t28 = *((char **)t27);
    t29 = ((char*)((ng3)));
    memset(t30, 0, 8);
    xsi_vlog_signed_add(t30, 32, t28, 32, t29, 32);
    t31 = (t0 + 920);
    xsi_vlogvar_assign_value(t31, t30, 0, 0, 32);
    goto LAB49;

LAB50:    xsi_set_current_line(49, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(50, ng0);
    t2 = (t0 + 1344);
    xsi_process_wait(t2, 7000LL);
    *((char **)t1) = &&LAB51;
    goto LAB1;

LAB51:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng7)));
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
        goto LAB55;

LAB52:    if (t16 != 0)
        goto LAB54;

LAB53:    *((unsigned int *)t4) = 1;

LAB55:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB56;

LAB57:    xsi_set_current_line(52, ng0);
    t2 = xsi_vlog_time(t32, 1000.0000000000000, 1000.0000000000000);
    xsi_vlogfile_write(0, 0, 0, ng4, 2, t0, (char)118, t32, 64);
    t3 = (t0 + 828);
    t5 = (t3 + 36U);
    t6 = *((char **)t5);
    t19 = (t0 + 600U);
    t20 = *((char **)t19);
    xsi_vlogfile_write(1, 0, 0, ng5, 3, t0, (char)118, t6, 4, (char)118, t20, 5);

LAB58:    xsi_set_current_line(54, ng0);
    t2 = (t0 + 1344);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB59;
    goto LAB1;

LAB54:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB55;

LAB56:    xsi_set_current_line(51, ng0);
    t26 = (t0 + 920);
    t27 = (t26 + 36U);
    t28 = *((char **)t27);
    t29 = ((char*)((ng3)));
    memset(t30, 0, 8);
    xsi_vlog_signed_add(t30, 32, t28, 32, t29, 32);
    t31 = (t0 + 920);
    xsi_vlogvar_assign_value(t31, t30, 0, 0, 32);
    goto LAB58;

LAB59:    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(56, ng0);
    t2 = (t0 + 1344);
    xsi_process_wait(t2, 7000LL);
    *((char **)t1) = &&LAB60;
    goto LAB1;

LAB60:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng7)));
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
        goto LAB64;

LAB61:    if (t16 != 0)
        goto LAB63;

LAB62:    *((unsigned int *)t4) = 1;

LAB64:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB65;

LAB66:    xsi_set_current_line(58, ng0);
    t2 = xsi_vlog_time(t32, 1000.0000000000000, 1000.0000000000000);
    xsi_vlogfile_write(0, 0, 0, ng4, 2, t0, (char)118, t32, 64);
    t3 = (t0 + 828);
    t5 = (t3 + 36U);
    t6 = *((char **)t5);
    t19 = (t0 + 600U);
    t20 = *((char **)t19);
    xsi_vlogfile_write(1, 0, 0, ng5, 3, t0, (char)118, t6, 4, (char)118, t20, 5);

LAB67:    xsi_set_current_line(60, ng0);
    t2 = (t0 + 1344);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB68;
    goto LAB1;

LAB63:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB64;

LAB65:    xsi_set_current_line(57, ng0);
    t26 = (t0 + 920);
    t27 = (t26 + 36U);
    t28 = *((char **)t27);
    t29 = ((char*)((ng3)));
    memset(t30, 0, 8);
    xsi_vlog_signed_add(t30, 32, t28, 32, t29, 32);
    t31 = (t0 + 920);
    xsi_vlogvar_assign_value(t31, t30, 0, 0, 32);
    goto LAB67;

LAB68:    xsi_set_current_line(61, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(62, ng0);
    t2 = (t0 + 1344);
    xsi_process_wait(t2, 7000LL);
    *((char **)t1) = &&LAB69;
    goto LAB1;

LAB69:    xsi_set_current_line(63, ng0);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng7)));
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
        goto LAB73;

LAB70:    if (t16 != 0)
        goto LAB72;

LAB71:    *((unsigned int *)t4) = 1;

LAB73:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB74;

LAB75:    xsi_set_current_line(64, ng0);
    t2 = xsi_vlog_time(t32, 1000.0000000000000, 1000.0000000000000);
    xsi_vlogfile_write(0, 0, 0, ng4, 2, t0, (char)118, t32, 64);
    t3 = (t0 + 828);
    t5 = (t3 + 36U);
    t6 = *((char **)t5);
    t19 = (t0 + 600U);
    t20 = *((char **)t19);
    xsi_vlogfile_write(1, 0, 0, ng5, 3, t0, (char)118, t6, 4, (char)118, t20, 5);

LAB76:    xsi_set_current_line(66, ng0);
    t2 = (t0 + 1344);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB77;
    goto LAB1;

LAB72:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB73;

LAB74:    xsi_set_current_line(63, ng0);
    t26 = (t0 + 920);
    t27 = (t26 + 36U);
    t28 = *((char **)t27);
    t29 = ((char*)((ng3)));
    memset(t30, 0, 8);
    xsi_vlog_signed_add(t30, 32, t28, 32, t29, 32);
    t31 = (t0 + 920);
    xsi_vlogvar_assign_value(t31, t30, 0, 0, 32);
    goto LAB76;

LAB77:    xsi_set_current_line(69, ng0);
    t2 = (t0 + 920);
    t3 = (t2 + 36U);
    t5 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng11, 2, t0, (char)119, t5, 32);
    xsi_set_current_line(70, ng0);
    xsi_vlogfile_write(1, 0, 0, ng12, 1, t0);
    xsi_set_current_line(71, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

}


extern void work_m_00000000001266750450_2149418644_init()
{
	static char *pe[] = {(void *)Initial_11_0};
	xsi_register_didat("work_m_00000000001266750450_2149418644", "isim/testbench_ROM_isim_beh.exe.sim/work/m_00000000001266750450_2149418644.didat");
	xsi_register_executes(pe);
}
