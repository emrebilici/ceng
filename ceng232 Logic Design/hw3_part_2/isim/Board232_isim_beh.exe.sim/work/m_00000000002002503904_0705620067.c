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
static const char *ng0 = "D:/DERS/ceng232/hw/hw3_part_2/Board232.v";
static unsigned int ng1[] = {1U, 0U};
static int ng2[] = {0, 0};
static unsigned int ng3[] = {63U, 0U};
static unsigned int ng4[] = {15U, 0U};
static int ng5[] = {1, 0};
static unsigned int ng6[] = {0U, 0U};
static unsigned int ng7[] = {14U, 0U};
static unsigned int ng8[] = {13U, 0U};
static unsigned int ng9[] = {2U, 0U};
static unsigned int ng10[] = {11U, 0U};
static unsigned int ng11[] = {7U, 0U};
static unsigned int ng12[] = {6U, 0U};
static unsigned int ng13[] = {91U, 0U};
static unsigned int ng14[] = {3U, 0U};
static unsigned int ng15[] = {79U, 0U};
static unsigned int ng16[] = {4U, 0U};
static unsigned int ng17[] = {102U, 0U};
static unsigned int ng18[] = {5U, 0U};
static unsigned int ng19[] = {109U, 0U};
static unsigned int ng20[] = {125U, 0U};
static unsigned int ng21[] = {8U, 0U};
static unsigned int ng22[] = {127U, 0U};
static unsigned int ng23[] = {9U, 0U};
static unsigned int ng24[] = {111U, 0U};
static unsigned int ng25[] = {10U, 0U};
static unsigned int ng26[] = {119U, 0U};
static unsigned int ng27[] = {124U, 0U};
static unsigned int ng28[] = {12U, 0U};
static unsigned int ng29[] = {57U, 0U};
static unsigned int ng30[] = {94U, 0U};
static unsigned int ng31[] = {121U, 0U};
static unsigned int ng32[] = {113U, 0U};



static void Cont_17_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 2916U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(17, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4900);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 0);

LAB1:    return;
}

static void Cont_18_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 3060U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(18, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4936);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 127U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 6);

LAB1:    return;
}

static void Initial_19_2(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(19, ng0);

LAB2:    xsi_set_current_line(20, ng0);
    t1 = ((char*)((ng3)));
    t2 = (t0 + 2024);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 7);
    xsi_set_current_line(21, ng0);
    t1 = ((char*)((ng4)));
    t2 = (t0 + 2116);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 4);

LAB1:    return;
}

static void Initial_27_3(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(27, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 2208);
    xsi_vlogvar_wait_assign_value(t2, t1, 0, 0, 27, 0LL);

LAB1:    return;
}

static void Always_28_4(char *t0)
{
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;

LAB0:    t1 = (t0 + 3492U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(28, ng0);
    t2 = (t0 + 4840);
    *((int *)t2) = 1;
    t3 = (t0 + 3520);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(28, ng0);
    t4 = (t0 + 2208);
    t5 = (t4 + 36U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng5)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 32, t6, 27, t7, 32);
    t9 = (t0 + 2208);
    xsi_vlogvar_assign_value(t9, t8, 0, 0, 27);
    goto LAB2;

}

static void Initial_32_5(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(32, ng0);
    t1 = ((char*)((ng6)));
    t2 = (t0 + 2300);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Always_33_6(char *t0)
{
    char t6[8];
    char t23[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t21;
    char *t22;
    char *t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;

LAB0:    t1 = (t0 + 3780U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(33, ng0);
    t2 = (t0 + 4848);
    *((int *)t2) = 1;
    t3 = (t0 + 3808);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(34, ng0);

LAB5:    xsi_set_current_line(35, ng0);
    t4 = (t0 + 784U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 2);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 2);
    t13 = (t12 & 1);
    *((unsigned int *)t4) = t13;
    t14 = (t6 + 4);
    t15 = *((unsigned int *)t14);
    t16 = (~(t15));
    t17 = *((unsigned int *)t6);
    t18 = (t17 & t16);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(38, ng0);
    t2 = (t0 + 692U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t8 = *((unsigned int *)t3);
    t9 = (t8 >> 0);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 0);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    t5 = (t0 + 2300);
    xsi_vlogvar_assign_value(t5, t6, 0, 0, 1);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(36, ng0);
    t20 = (t0 + 2208);
    t21 = (t20 + 36U);
    t22 = *((char **)t21);
    memset(t23, 0, 8);
    t24 = (t23 + 4);
    t25 = (t22 + 4);
    t26 = *((unsigned int *)t22);
    t27 = (t26 >> 25);
    t28 = (t27 & 1);
    *((unsigned int *)t23) = t28;
    t29 = *((unsigned int *)t25);
    t30 = (t29 >> 25);
    t31 = (t30 & 1);
    *((unsigned int *)t24) = t31;
    t32 = (t0 + 2300);
    xsi_vlogvar_assign_value(t32, t23, 0, 0, 1);
    goto LAB8;

}

static void Always_58_7(char *t0)
{
    char t4[8];
    char t20[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    int t17;
    char *t18;
    char *t19;
    unsigned int t21;
    unsigned int t22;

LAB0:    t1 = (t0 + 3924U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(58, ng0);
    t2 = (t0 + 4856);
    *((int *)t2) = 1;
    t3 = (t0 + 3952);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(59, ng0);

LAB5:    xsi_set_current_line(60, ng0);
    t5 = (t0 + 2208);
    t6 = (t5 + 36U);
    t7 = *((char **)t6);
    memset(t4, 0, 8);
    t8 = (t4 + 4);
    t9 = (t7 + 4);
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 17);
    *((unsigned int *)t4) = t11;
    t12 = *((unsigned int *)t9);
    t13 = (t12 >> 17);
    *((unsigned int *)t8) = t13;
    t14 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t14 & 3U);
    t15 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t15 & 3U);

LAB6:    t16 = ((char*)((ng6)));
    t17 = xsi_vlog_unsigned_case_compare(t4, 2, t16, 2);
    if (t17 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng1)));
    t17 = xsi_vlog_unsigned_case_compare(t4, 2, t2, 2);
    if (t17 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng9)));
    t17 = xsi_vlog_unsigned_case_compare(t4, 2, t2, 2);
    if (t17 == 1)
        goto LAB11;

LAB12:
LAB14:
LAB13:    xsi_set_current_line(77, ng0);

LAB19:    xsi_set_current_line(78, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 2116);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(79, ng0);
    t2 = (t0 + 1704U);
    t3 = *((char **)t2);
    t2 = (t0 + 2392);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 8);

LAB15:    xsi_set_current_line(83, ng0);
    t2 = (t0 + 2392);
    t3 = (t2 + 36U);
    t5 = *((char **)t3);

LAB20:    t6 = ((char*)((ng6)));
    t17 = xsi_vlog_unsigned_case_compare(t5, 8, t6, 8);
    if (t17 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng1)));
    t17 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 8);
    if (t17 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng9)));
    t17 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 8);
    if (t17 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng14)));
    t17 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 8);
    if (t17 == 1)
        goto LAB27;

LAB28:    t2 = ((char*)((ng16)));
    t17 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 8);
    if (t17 == 1)
        goto LAB29;

LAB30:    t2 = ((char*)((ng18)));
    t17 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 8);
    if (t17 == 1)
        goto LAB31;

LAB32:    t2 = ((char*)((ng12)));
    t17 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 8);
    if (t17 == 1)
        goto LAB33;

LAB34:    t2 = ((char*)((ng11)));
    t17 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 8);
    if (t17 == 1)
        goto LAB35;

LAB36:    t2 = ((char*)((ng21)));
    t17 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 8);
    if (t17 == 1)
        goto LAB37;

LAB38:    t2 = ((char*)((ng23)));
    t17 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 8);
    if (t17 == 1)
        goto LAB39;

LAB40:    t2 = ((char*)((ng25)));
    t17 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 8);
    if (t17 == 1)
        goto LAB41;

LAB42:    t2 = ((char*)((ng10)));
    t17 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 8);
    if (t17 == 1)
        goto LAB43;

LAB44:    t2 = ((char*)((ng28)));
    t17 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 8);
    if (t17 == 1)
        goto LAB45;

LAB46:    t2 = ((char*)((ng8)));
    t17 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 8);
    if (t17 == 1)
        goto LAB47;

LAB48:    t2 = ((char*)((ng7)));
    t17 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 8);
    if (t17 == 1)
        goto LAB49;

LAB50:    t2 = ((char*)((ng4)));
    t17 = xsi_vlog_unsigned_case_compare(t5, 8, t2, 8);
    if (t17 == 1)
        goto LAB51;

LAB52:
LAB54:
LAB53:    xsi_set_current_line(100, ng0);
    t2 = ((char*)((ng6)));
    memset(t20, 0, 8);
    t3 = (t20 + 4);
    t6 = (t2 + 4);
    t10 = *((unsigned int *)t2);
    t11 = (~(t10));
    *((unsigned int *)t20) = t11;
    *((unsigned int *)t3) = 0;
    if (*((unsigned int *)t6) != 0)
        goto LAB89;

LAB88:    t21 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t21 & 127U);
    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 127U);
    t7 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t7, t20, 0, 0, 7, 0LL);

LAB55:    goto LAB2;

LAB7:    xsi_set_current_line(62, ng0);

LAB16:    xsi_set_current_line(63, ng0);
    t18 = ((char*)((ng7)));
    t19 = (t0 + 2116);
    xsi_vlogvar_assign_value(t19, t18, 0, 0, 4);
    xsi_set_current_line(64, ng0);
    t2 = (t0 + 1612U);
    t3 = *((char **)t2);
    t2 = (t0 + 2392);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 8);
    goto LAB15;

LAB9:    xsi_set_current_line(67, ng0);

LAB17:    xsi_set_current_line(68, ng0);
    t3 = ((char*)((ng8)));
    t5 = (t0 + 2116);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 4);
    xsi_set_current_line(69, ng0);
    t2 = (t0 + 1520U);
    t3 = *((char **)t2);
    t2 = (t0 + 2392);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 8);
    goto LAB15;

LAB11:    xsi_set_current_line(72, ng0);

LAB18:    xsi_set_current_line(73, ng0);
    t3 = ((char*)((ng10)));
    t5 = (t0 + 2116);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 4);
    xsi_set_current_line(74, ng0);
    t2 = (t0 + 1796U);
    t3 = *((char **)t2);
    t2 = (t0 + 2392);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 8);
    goto LAB15;

LAB21:    xsi_set_current_line(84, ng0);
    t7 = ((char*)((ng3)));
    memset(t20, 0, 8);
    t8 = (t20 + 4);
    t9 = (t7 + 4);
    t10 = *((unsigned int *)t7);
    t11 = (~(t10));
    *((unsigned int *)t20) = t11;
    *((unsigned int *)t8) = 0;
    if (*((unsigned int *)t9) != 0)
        goto LAB57;

LAB56:    t21 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t21 & 127U);
    t22 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t22 & 127U);
    t16 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t16, t20, 0, 0, 7, 0LL);
    goto LAB55;

LAB23:    xsi_set_current_line(85, ng0);
    t3 = ((char*)((ng12)));
    memset(t20, 0, 8);
    t6 = (t20 + 4);
    t7 = (t3 + 4);
    t10 = *((unsigned int *)t3);
    t11 = (~(t10));
    *((unsigned int *)t20) = t11;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB59;

LAB58:    t21 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t21 & 127U);
    t22 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t22 & 127U);
    t8 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t8, t20, 0, 0, 7, 0LL);
    goto LAB55;

LAB25:    xsi_set_current_line(86, ng0);
    t3 = ((char*)((ng13)));
    memset(t20, 0, 8);
    t6 = (t20 + 4);
    t7 = (t3 + 4);
    t10 = *((unsigned int *)t3);
    t11 = (~(t10));
    *((unsigned int *)t20) = t11;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB61;

LAB60:    t21 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t21 & 127U);
    t22 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t22 & 127U);
    t8 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t8, t20, 0, 0, 7, 0LL);
    goto LAB55;

LAB27:    xsi_set_current_line(87, ng0);
    t3 = ((char*)((ng15)));
    memset(t20, 0, 8);
    t6 = (t20 + 4);
    t7 = (t3 + 4);
    t10 = *((unsigned int *)t3);
    t11 = (~(t10));
    *((unsigned int *)t20) = t11;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB63;

LAB62:    t21 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t21 & 127U);
    t22 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t22 & 127U);
    t8 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t8, t20, 0, 0, 7, 0LL);
    goto LAB55;

LAB29:    xsi_set_current_line(88, ng0);
    t3 = ((char*)((ng17)));
    memset(t20, 0, 8);
    t6 = (t20 + 4);
    t7 = (t3 + 4);
    t10 = *((unsigned int *)t3);
    t11 = (~(t10));
    *((unsigned int *)t20) = t11;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB65;

LAB64:    t21 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t21 & 127U);
    t22 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t22 & 127U);
    t8 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t8, t20, 0, 0, 7, 0LL);
    goto LAB55;

LAB31:    xsi_set_current_line(89, ng0);
    t3 = ((char*)((ng19)));
    memset(t20, 0, 8);
    t6 = (t20 + 4);
    t7 = (t3 + 4);
    t10 = *((unsigned int *)t3);
    t11 = (~(t10));
    *((unsigned int *)t20) = t11;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB67;

LAB66:    t21 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t21 & 127U);
    t22 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t22 & 127U);
    t8 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t8, t20, 0, 0, 7, 0LL);
    goto LAB55;

LAB33:    xsi_set_current_line(90, ng0);
    t3 = ((char*)((ng20)));
    memset(t20, 0, 8);
    t6 = (t20 + 4);
    t7 = (t3 + 4);
    t10 = *((unsigned int *)t3);
    t11 = (~(t10));
    *((unsigned int *)t20) = t11;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB69;

LAB68:    t21 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t21 & 127U);
    t22 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t22 & 127U);
    t8 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t8, t20, 0, 0, 7, 0LL);
    goto LAB55;

LAB35:    xsi_set_current_line(91, ng0);
    t3 = ((char*)((ng11)));
    memset(t20, 0, 8);
    t6 = (t20 + 4);
    t7 = (t3 + 4);
    t10 = *((unsigned int *)t3);
    t11 = (~(t10));
    *((unsigned int *)t20) = t11;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB71;

LAB70:    t21 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t21 & 127U);
    t22 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t22 & 127U);
    t8 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t8, t20, 0, 0, 7, 0LL);
    goto LAB55;

LAB37:    xsi_set_current_line(92, ng0);
    t3 = ((char*)((ng22)));
    memset(t20, 0, 8);
    t6 = (t20 + 4);
    t7 = (t3 + 4);
    t10 = *((unsigned int *)t3);
    t11 = (~(t10));
    *((unsigned int *)t20) = t11;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB73;

LAB72:    t21 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t21 & 127U);
    t22 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t22 & 127U);
    t8 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t8, t20, 0, 0, 7, 0LL);
    goto LAB55;

LAB39:    xsi_set_current_line(93, ng0);
    t3 = ((char*)((ng24)));
    memset(t20, 0, 8);
    t6 = (t20 + 4);
    t7 = (t3 + 4);
    t10 = *((unsigned int *)t3);
    t11 = (~(t10));
    *((unsigned int *)t20) = t11;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB75;

LAB74:    t21 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t21 & 127U);
    t22 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t22 & 127U);
    t8 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t8, t20, 0, 0, 7, 0LL);
    goto LAB55;

LAB41:    xsi_set_current_line(94, ng0);
    t3 = ((char*)((ng26)));
    memset(t20, 0, 8);
    t6 = (t20 + 4);
    t7 = (t3 + 4);
    t10 = *((unsigned int *)t3);
    t11 = (~(t10));
    *((unsigned int *)t20) = t11;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB77;

LAB76:    t21 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t21 & 127U);
    t22 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t22 & 127U);
    t8 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t8, t20, 0, 0, 7, 0LL);
    goto LAB55;

LAB43:    xsi_set_current_line(95, ng0);
    t3 = ((char*)((ng27)));
    memset(t20, 0, 8);
    t6 = (t20 + 4);
    t7 = (t3 + 4);
    t10 = *((unsigned int *)t3);
    t11 = (~(t10));
    *((unsigned int *)t20) = t11;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB79;

LAB78:    t21 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t21 & 127U);
    t22 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t22 & 127U);
    t8 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t8, t20, 0, 0, 7, 0LL);
    goto LAB55;

LAB45:    xsi_set_current_line(96, ng0);
    t3 = ((char*)((ng29)));
    memset(t20, 0, 8);
    t6 = (t20 + 4);
    t7 = (t3 + 4);
    t10 = *((unsigned int *)t3);
    t11 = (~(t10));
    *((unsigned int *)t20) = t11;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB81;

LAB80:    t21 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t21 & 127U);
    t22 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t22 & 127U);
    t8 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t8, t20, 0, 0, 7, 0LL);
    goto LAB55;

LAB47:    xsi_set_current_line(97, ng0);
    t3 = ((char*)((ng30)));
    memset(t20, 0, 8);
    t6 = (t20 + 4);
    t7 = (t3 + 4);
    t10 = *((unsigned int *)t3);
    t11 = (~(t10));
    *((unsigned int *)t20) = t11;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB83;

LAB82:    t21 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t21 & 127U);
    t22 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t22 & 127U);
    t8 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t8, t20, 0, 0, 7, 0LL);
    goto LAB55;

LAB49:    xsi_set_current_line(98, ng0);
    t3 = ((char*)((ng31)));
    memset(t20, 0, 8);
    t6 = (t20 + 4);
    t7 = (t3 + 4);
    t10 = *((unsigned int *)t3);
    t11 = (~(t10));
    *((unsigned int *)t20) = t11;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB85;

LAB84:    t21 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t21 & 127U);
    t22 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t22 & 127U);
    t8 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t8, t20, 0, 0, 7, 0LL);
    goto LAB55;

LAB51:    xsi_set_current_line(99, ng0);
    t3 = ((char*)((ng32)));
    memset(t20, 0, 8);
    t6 = (t20 + 4);
    t7 = (t3 + 4);
    t10 = *((unsigned int *)t3);
    t11 = (~(t10));
    *((unsigned int *)t20) = t11;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB87;

LAB86:    t21 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t21 & 127U);
    t22 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t22 & 127U);
    t8 = (t0 + 2024);
    xsi_vlogvar_wait_assign_value(t8, t20, 0, 0, 7, 0LL);
    goto LAB55;

LAB57:    t12 = *((unsigned int *)t20);
    t13 = *((unsigned int *)t9);
    *((unsigned int *)t20) = (t12 | t13);
    t14 = *((unsigned int *)t8);
    t15 = *((unsigned int *)t9);
    *((unsigned int *)t8) = (t14 | t15);
    goto LAB56;

LAB59:    t12 = *((unsigned int *)t20);
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t20) = (t12 | t13);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t14 | t15);
    goto LAB58;

LAB61:    t12 = *((unsigned int *)t20);
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t20) = (t12 | t13);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t14 | t15);
    goto LAB60;

LAB63:    t12 = *((unsigned int *)t20);
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t20) = (t12 | t13);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t14 | t15);
    goto LAB62;

LAB65:    t12 = *((unsigned int *)t20);
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t20) = (t12 | t13);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t14 | t15);
    goto LAB64;

LAB67:    t12 = *((unsigned int *)t20);
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t20) = (t12 | t13);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t14 | t15);
    goto LAB66;

LAB69:    t12 = *((unsigned int *)t20);
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t20) = (t12 | t13);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t14 | t15);
    goto LAB68;

LAB71:    t12 = *((unsigned int *)t20);
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t20) = (t12 | t13);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t14 | t15);
    goto LAB70;

LAB73:    t12 = *((unsigned int *)t20);
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t20) = (t12 | t13);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t14 | t15);
    goto LAB72;

LAB75:    t12 = *((unsigned int *)t20);
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t20) = (t12 | t13);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t14 | t15);
    goto LAB74;

LAB77:    t12 = *((unsigned int *)t20);
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t20) = (t12 | t13);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t14 | t15);
    goto LAB76;

LAB79:    t12 = *((unsigned int *)t20);
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t20) = (t12 | t13);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t14 | t15);
    goto LAB78;

LAB81:    t12 = *((unsigned int *)t20);
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t20) = (t12 | t13);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t14 | t15);
    goto LAB80;

LAB83:    t12 = *((unsigned int *)t20);
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t20) = (t12 | t13);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t14 | t15);
    goto LAB82;

LAB85:    t12 = *((unsigned int *)t20);
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t20) = (t12 | t13);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t14 | t15);
    goto LAB84;

LAB87:    t12 = *((unsigned int *)t20);
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t20) = (t12 | t13);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t14 | t15);
    goto LAB86;

LAB89:    t12 = *((unsigned int *)t20);
    t13 = *((unsigned int *)t6);
    *((unsigned int *)t20) = (t12 | t13);
    t14 = *((unsigned int *)t3);
    t15 = *((unsigned int *)t6);
    *((unsigned int *)t3) = (t14 | t15);
    goto LAB88;

}

static void Cont_106_8(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 4068U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(106, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4972);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 3U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 1);

LAB1:    return;
}

static void Cont_107_9(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 4212U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(107, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 5008);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 7U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 2);

LAB1:    return;
}

static void Cont_108_10(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 4356U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(108, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 5044);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 7U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 2);

LAB1:    return;
}

static void Cont_109_11(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 4500U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(109, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 5080);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 0);

LAB1:    return;
}

static void Cont_110_12(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 4644U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(110, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 5116);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 0);

LAB1:    return;
}


extern void work_m_00000000002002503904_0705620067_init()
{
	static char *pe[] = {(void *)Cont_17_0,(void *)Cont_18_1,(void *)Initial_19_2,(void *)Initial_27_3,(void *)Always_28_4,(void *)Initial_32_5,(void *)Always_33_6,(void *)Always_58_7,(void *)Cont_106_8,(void *)Cont_107_9,(void *)Cont_108_10,(void *)Cont_109_11,(void *)Cont_110_12};
	xsi_register_didat("work_m_00000000002002503904_0705620067", "isim/Board232_isim_beh.exe.sim/work/m_00000000002002503904_0705620067.didat");
	xsi_register_executes(pe);
}
