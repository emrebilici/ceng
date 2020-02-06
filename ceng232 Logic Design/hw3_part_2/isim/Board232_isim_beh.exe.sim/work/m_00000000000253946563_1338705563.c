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
static const char *ng0 = "D:/DERS/ceng232/hw/hw3_part_2/lab3_2.v";
static int ng1[] = {0, 0};
static int ng2[] = {4, 0};
static int ng3[] = {1, 0};
static unsigned int ng4[] = {9U, 0U};

static void NetReassign_28_2(char *);
static void NetReassign_33_3(char *);
static void NetReassign_66_4(char *);


static void Initial_18_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(18, ng0);

LAB2:    xsi_set_current_line(19, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 1196);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 8);
    xsi_set_current_line(20, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 1380);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 8);
    xsi_set_current_line(21, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 1104);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 8);
    xsi_set_current_line(22, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 1288);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 8);
    xsi_set_current_line(23, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 1472);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(24, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 1656);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);

LAB1:    return;
}

static void Always_27_1(char *t0)
{
    char t6[8];
    char t28[8];
    char t34[8];
    char t46[8];
    char t53[8];
    char t55[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
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
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;
    char *t47;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t54;
    char *t56;
    char *t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    char *t70;
    char *t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    char *t77;
    char *t78;
    int t79;
    int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;

LAB0:    t1 = (t0 + 2324U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(27, ng0);
    t2 = (t0 + 2952);
    *((int *)t2) = 1;
    t3 = (t0 + 2352);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(27, ng0);

LAB5:    xsi_set_current_line(28, ng0);
    t4 = (t0 + 1656);
    xsi_set_assignedflag(t4);
    t5 = (t0 + 4200);
    *((int *)t5) = 1;
    NetReassign_28_2(t0);
    xsi_set_current_line(29, ng0);
    t2 = (t0 + 784U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t4);
    t11 = *((unsigned int *)t5);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t4);
    t15 = *((unsigned int *)t5);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB9;

LAB6:    if (t16 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t6) = 1;

LAB9:    t20 = (t6 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t6);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB10;

LAB11:
LAB12:    xsi_set_current_line(62, ng0);
    t2 = (t0 + 784U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t4);
    t11 = *((unsigned int *)t5);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t4);
    t15 = *((unsigned int *)t5);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB65;

LAB62:    if (t16 != 0)
        goto LAB64;

LAB63:    *((unsigned int *)t6) = 1;

LAB65:    t20 = (t6 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t6);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB66;

LAB67:
LAB68:    goto LAB2;

LAB8:    t19 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(29, ng0);

LAB13:    xsi_set_current_line(30, ng0);
    xsi_set_current_line(30, ng0);
    t26 = ((char*)((ng1)));
    t27 = (t0 + 1564);
    xsi_vlogvar_assign_value(t27, t26, 0, 0, 32);

LAB14:    t2 = (t0 + 1564);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_signed_less(t6, 32, t4, 32, t5, 32);
    t19 = (t6 + 4);
    t7 = *((unsigned int *)t19);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB15;

LAB16:    xsi_set_current_line(36, ng0);
    t2 = (t0 + 1656);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB32;

LAB33:    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1472);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB34:    goto LAB12;

LAB15:    xsi_set_current_line(30, ng0);

LAB17:    xsi_set_current_line(31, ng0);
    t20 = (t0 + 600U);
    t26 = *((char **)t20);
    t20 = (t0 + 576U);
    t27 = (t20 + 44U);
    t29 = *((char **)t27);
    t30 = (t0 + 1564);
    t31 = (t30 + 36U);
    t32 = *((char **)t31);
    xsi_vlog_generic_get_index_select_value(t28, 32, t26, t29, 2, t32, 32, 1);
    t33 = ((char*)((ng1)));
    memset(t34, 0, 8);
    t35 = (t28 + 4);
    t36 = (t33 + 4);
    t12 = *((unsigned int *)t28);
    t13 = *((unsigned int *)t33);
    t14 = (t12 ^ t13);
    t15 = *((unsigned int *)t35);
    t16 = *((unsigned int *)t36);
    t17 = (t15 ^ t16);
    t18 = (t14 | t17);
    t21 = *((unsigned int *)t35);
    t22 = *((unsigned int *)t36);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t18 & t24);
    if (t25 != 0)
        goto LAB21;

LAB18:    if (t23 != 0)
        goto LAB20;

LAB19:    *((unsigned int *)t34) = 1;

LAB21:    t38 = (t34 + 4);
    t39 = *((unsigned int *)t38);
    t40 = (~(t39));
    t41 = *((unsigned int *)t34);
    t42 = (t41 & t40);
    t43 = (t42 != 0);
    if (t43 > 0)
        goto LAB22;

LAB23:
LAB24:    xsi_set_current_line(30, ng0);
    t2 = (t0 + 1564);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_signed_add(t6, 32, t4, 32, t5, 32);
    t19 = (t0 + 1564);
    xsi_vlogvar_assign_value(t19, t6, 0, 0, 32);
    goto LAB14;

LAB20:    t37 = (t34 + 4);
    *((unsigned int *)t34) = 1;
    *((unsigned int *)t37) = 1;
    goto LAB21;

LAB22:    xsi_set_current_line(32, ng0);
    t44 = (t0 + 600U);
    t45 = *((char **)t44);
    t44 = (t0 + 576U);
    t47 = (t44 + 44U);
    t48 = *((char **)t47);
    t49 = (t0 + 1564);
    t50 = (t49 + 36U);
    t51 = *((char **)t50);
    t52 = ((char*)((ng3)));
    memset(t53, 0, 8);
    xsi_vlog_signed_add(t53, 32, t51, 32, t52, 32);
    xsi_vlog_generic_get_index_select_value(t46, 32, t45, t48, 2, t53, 32, 1);
    t54 = ((char*)((ng1)));
    memset(t55, 0, 8);
    t56 = (t46 + 4);
    t57 = (t54 + 4);
    t58 = *((unsigned int *)t46);
    t59 = *((unsigned int *)t54);
    t60 = (t58 ^ t59);
    t61 = *((unsigned int *)t56);
    t62 = *((unsigned int *)t57);
    t63 = (t61 ^ t62);
    t64 = (t60 | t63);
    t65 = *((unsigned int *)t56);
    t66 = *((unsigned int *)t57);
    t67 = (t65 | t66);
    t68 = (~(t67));
    t69 = (t64 & t68);
    if (t69 != 0)
        goto LAB28;

LAB25:    if (t67 != 0)
        goto LAB27;

LAB26:    *((unsigned int *)t55) = 1;

LAB28:    t71 = (t55 + 4);
    t72 = *((unsigned int *)t71);
    t73 = (~(t72));
    t74 = *((unsigned int *)t55);
    t75 = (t74 & t73);
    t76 = (t75 != 0);
    if (t76 > 0)
        goto LAB29;

LAB30:
LAB31:    goto LAB24;

LAB27:    t70 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t70) = 1;
    goto LAB28;

LAB29:    xsi_set_current_line(33, ng0);
    t77 = (t0 + 1656);
    xsi_set_assignedflag(t77);
    t78 = (t0 + 4204);
    *((int *)t78) = 1;
    NetReassign_33_3(t0);
    goto LAB31;

LAB32:    xsi_set_current_line(36, ng0);

LAB35:    xsi_set_current_line(37, ng0);
    t19 = ((char*)((ng1)));
    t20 = (t0 + 1472);
    xsi_vlogvar_wait_assign_value(t20, t19, 0, 0, 1, 0LL);
    xsi_set_current_line(38, ng0);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB36;

LAB37:    xsi_set_current_line(47, ng0);

LAB47:    xsi_set_current_line(48, ng0);
    t2 = (t0 + 1196);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = (t0 + 1104);
    t19 = (t5 + 36U);
    t20 = *((char **)t19);
    t7 = *((unsigned int *)t4);
    t8 = *((unsigned int *)t20);
    t9 = (t7 | t8);
    *((unsigned int *)t6) = t9;
    t26 = (t4 + 4);
    t27 = (t20 + 4);
    t29 = (t6 + 4);
    t10 = *((unsigned int *)t26);
    t11 = *((unsigned int *)t27);
    t12 = (t10 | t11);
    *((unsigned int *)t29) = t12;
    t13 = *((unsigned int *)t29);
    t14 = (t13 != 0);
    if (t14 == 1)
        goto LAB48;

LAB49:
LAB50:    t32 = (t6 + 4);
    t42 = *((unsigned int *)t32);
    t43 = (~(t42));
    t58 = *((unsigned int *)t6);
    t59 = (t58 & t43);
    t60 = (t59 != 0);
    if (t60 > 0)
        goto LAB51;

LAB52:
LAB53:
LAB38:    goto LAB34;

LAB36:    xsi_set_current_line(38, ng0);

LAB39:    xsi_set_current_line(39, ng0);
    t4 = (t0 + 1196);
    t5 = (t4 + 36U);
    t19 = *((char **)t5);
    t20 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 32, t19, 8, t20, 32);
    t26 = (t0 + 1196);
    xsi_vlogvar_wait_assign_value(t26, t6, 0, 0, 8, 0LL);
    xsi_set_current_line(41, ng0);
    t2 = (t0 + 1196);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t19 = (t4 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (t7 >> 0);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t19);
    t11 = (t10 >> 0);
    t12 = (t11 & 1);
    *((unsigned int *)t5) = t12;
    t20 = (t0 + 1196);
    t26 = (t20 + 36U);
    t27 = *((char **)t26);
    memset(t28, 0, 8);
    t29 = (t28 + 4);
    t30 = (t27 + 4);
    t13 = *((unsigned int *)t27);
    t14 = (t13 >> 3);
    t15 = (t14 & 1);
    *((unsigned int *)t28) = t15;
    t16 = *((unsigned int *)t30);
    t17 = (t16 >> 3);
    t18 = (t17 & 1);
    *((unsigned int *)t29) = t18;
    t21 = *((unsigned int *)t6);
    t22 = *((unsigned int *)t28);
    t23 = (t21 & t22);
    *((unsigned int *)t34) = t23;
    t31 = (t6 + 4);
    t32 = (t28 + 4);
    t33 = (t34 + 4);
    t24 = *((unsigned int *)t31);
    t25 = *((unsigned int *)t32);
    t39 = (t24 | t25);
    *((unsigned int *)t33) = t39;
    t40 = *((unsigned int *)t33);
    t41 = (t40 != 0);
    if (t41 == 1)
        goto LAB40;

LAB41:
LAB42:    t37 = (t34 + 4);
    t74 = *((unsigned int *)t37);
    t75 = (~(t74));
    t76 = *((unsigned int *)t34);
    t81 = (t76 & t75);
    t82 = (t81 != 0);
    if (t82 > 0)
        goto LAB43;

LAB44:
LAB45:    goto LAB38;

LAB40:    t42 = *((unsigned int *)t34);
    t43 = *((unsigned int *)t33);
    *((unsigned int *)t34) = (t42 | t43);
    t35 = (t6 + 4);
    t36 = (t28 + 4);
    t58 = *((unsigned int *)t6);
    t59 = (~(t58));
    t60 = *((unsigned int *)t35);
    t61 = (~(t60));
    t62 = *((unsigned int *)t28);
    t63 = (~(t62));
    t64 = *((unsigned int *)t36);
    t65 = (~(t64));
    t79 = (t59 & t61);
    t80 = (t63 & t65);
    t66 = (~(t79));
    t67 = (~(t80));
    t68 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t68 & t66);
    t69 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t69 & t67);
    t72 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t72 & t66);
    t73 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t73 & t67);
    goto LAB42;

LAB43:    xsi_set_current_line(41, ng0);

LAB46:    xsi_set_current_line(42, ng0);
    t38 = ((char*)((ng1)));
    t44 = (t0 + 1196);
    xsi_vlogvar_wait_assign_value(t44, t38, 0, 0, 8, 0LL);
    xsi_set_current_line(43, ng0);
    t2 = (t0 + 1104);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 32, t4, 8, t5, 32);
    t19 = (t0 + 1104);
    xsi_vlogvar_wait_assign_value(t19, t6, 0, 0, 8, 0LL);
    goto LAB45;

LAB48:    t15 = *((unsigned int *)t6);
    t16 = *((unsigned int *)t29);
    *((unsigned int *)t6) = (t15 | t16);
    t30 = (t4 + 4);
    t31 = (t20 + 4);
    t17 = *((unsigned int *)t30);
    t18 = (~(t17));
    t21 = *((unsigned int *)t4);
    t79 = (t21 & t18);
    t22 = *((unsigned int *)t31);
    t23 = (~(t22));
    t24 = *((unsigned int *)t20);
    t80 = (t24 & t23);
    t25 = (~(t79));
    t39 = (~(t80));
    t40 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t40 & t25);
    t41 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t41 & t39);
    goto LAB50;

LAB51:    xsi_set_current_line(49, ng0);
    t33 = (t0 + 1196);
    t35 = (t33 + 36U);
    t36 = *((char **)t35);
    t37 = ((char*)((ng1)));
    memset(t28, 0, 8);
    t38 = (t36 + 4);
    t44 = (t37 + 4);
    t61 = *((unsigned int *)t36);
    t62 = *((unsigned int *)t37);
    t63 = (t61 ^ t62);
    t64 = *((unsigned int *)t38);
    t65 = *((unsigned int *)t44);
    t66 = (t64 ^ t65);
    t67 = (t63 | t66);
    t68 = *((unsigned int *)t38);
    t69 = *((unsigned int *)t44);
    t72 = (t68 | t69);
    t73 = (~(t72));
    t74 = (t67 & t73);
    if (t74 != 0)
        goto LAB57;

LAB54:    if (t72 != 0)
        goto LAB56;

LAB55:    *((unsigned int *)t28) = 1;

LAB57:    t47 = (t28 + 4);
    t75 = *((unsigned int *)t47);
    t76 = (~(t75));
    t81 = *((unsigned int *)t28);
    t82 = (t81 & t76);
    t83 = (t82 != 0);
    if (t83 > 0)
        goto LAB58;

LAB59:    xsi_set_current_line(54, ng0);
    t2 = (t0 + 1196);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_minus(t6, 32, t4, 8, t5, 32);
    t19 = (t0 + 1196);
    xsi_vlogvar_wait_assign_value(t19, t6, 0, 0, 8, 0LL);

LAB60:    goto LAB53;

LAB56:    t45 = (t28 + 4);
    *((unsigned int *)t28) = 1;
    *((unsigned int *)t45) = 1;
    goto LAB57;

LAB58:    xsi_set_current_line(49, ng0);

LAB61:    xsi_set_current_line(50, ng0);
    t48 = (t0 + 1104);
    t49 = (t48 + 36U);
    t50 = *((char **)t49);
    t51 = ((char*)((ng3)));
    memset(t34, 0, 8);
    xsi_vlog_unsigned_minus(t34, 32, t50, 8, t51, 32);
    t52 = (t0 + 1104);
    xsi_vlogvar_wait_assign_value(t52, t34, 0, 0, 8, 0LL);
    xsi_set_current_line(51, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1196);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 0LL);
    goto LAB60;

LAB64:    t19 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB65;

LAB66:    xsi_set_current_line(62, ng0);

LAB69:    xsi_set_current_line(63, ng0);
    xsi_set_current_line(63, ng0);
    t26 = ((char*)((ng1)));
    t27 = (t0 + 1564);
    xsi_vlogvar_assign_value(t27, t26, 0, 0, 32);

LAB70:    t2 = (t0 + 1564);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_signed_less(t6, 32, t4, 32, t5, 32);
    t19 = (t6 + 4);
    t7 = *((unsigned int *)t19);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB71;

LAB72:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 1656);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB88;

LAB89:    xsi_set_current_line(91, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1472);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB90:    goto LAB68;

LAB71:    xsi_set_current_line(63, ng0);

LAB73:    xsi_set_current_line(64, ng0);
    t20 = (t0 + 600U);
    t26 = *((char **)t20);
    t20 = (t0 + 576U);
    t27 = (t20 + 44U);
    t29 = *((char **)t27);
    t30 = (t0 + 1564);
    t31 = (t30 + 36U);
    t32 = *((char **)t31);
    xsi_vlog_generic_get_index_select_value(t28, 32, t26, t29, 2, t32, 32, 1);
    t33 = ((char*)((ng3)));
    memset(t34, 0, 8);
    t35 = (t28 + 4);
    t36 = (t33 + 4);
    t12 = *((unsigned int *)t28);
    t13 = *((unsigned int *)t33);
    t14 = (t12 ^ t13);
    t15 = *((unsigned int *)t35);
    t16 = *((unsigned int *)t36);
    t17 = (t15 ^ t16);
    t18 = (t14 | t17);
    t21 = *((unsigned int *)t35);
    t22 = *((unsigned int *)t36);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t18 & t24);
    if (t25 != 0)
        goto LAB77;

LAB74:    if (t23 != 0)
        goto LAB76;

LAB75:    *((unsigned int *)t34) = 1;

LAB77:    t38 = (t34 + 4);
    t39 = *((unsigned int *)t38);
    t40 = (~(t39));
    t41 = *((unsigned int *)t34);
    t42 = (t41 & t40);
    t43 = (t42 != 0);
    if (t43 > 0)
        goto LAB78;

LAB79:
LAB80:    xsi_set_current_line(63, ng0);
    t2 = (t0 + 1564);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_signed_add(t6, 32, t4, 32, t5, 32);
    t19 = (t0 + 1564);
    xsi_vlogvar_assign_value(t19, t6, 0, 0, 32);
    goto LAB70;

LAB76:    t37 = (t34 + 4);
    *((unsigned int *)t34) = 1;
    *((unsigned int *)t37) = 1;
    goto LAB77;

LAB78:    xsi_set_current_line(65, ng0);
    t44 = (t0 + 600U);
    t45 = *((char **)t44);
    t44 = (t0 + 576U);
    t47 = (t44 + 44U);
    t48 = *((char **)t47);
    t49 = (t0 + 1564);
    t50 = (t49 + 36U);
    t51 = *((char **)t50);
    t52 = ((char*)((ng3)));
    memset(t53, 0, 8);
    xsi_vlog_signed_add(t53, 32, t51, 32, t52, 32);
    xsi_vlog_generic_get_index_select_value(t46, 32, t45, t48, 2, t53, 32, 1);
    t54 = ((char*)((ng3)));
    memset(t55, 0, 8);
    t56 = (t46 + 4);
    t57 = (t54 + 4);
    t58 = *((unsigned int *)t46);
    t59 = *((unsigned int *)t54);
    t60 = (t58 ^ t59);
    t61 = *((unsigned int *)t56);
    t62 = *((unsigned int *)t57);
    t63 = (t61 ^ t62);
    t64 = (t60 | t63);
    t65 = *((unsigned int *)t56);
    t66 = *((unsigned int *)t57);
    t67 = (t65 | t66);
    t68 = (~(t67));
    t69 = (t64 & t68);
    if (t69 != 0)
        goto LAB84;

LAB81:    if (t67 != 0)
        goto LAB83;

LAB82:    *((unsigned int *)t55) = 1;

LAB84:    t71 = (t55 + 4);
    t72 = *((unsigned int *)t71);
    t73 = (~(t72));
    t74 = *((unsigned int *)t55);
    t75 = (t74 & t73);
    t76 = (t75 != 0);
    if (t76 > 0)
        goto LAB85;

LAB86:
LAB87:    goto LAB80;

LAB83:    t70 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t70) = 1;
    goto LAB84;

LAB85:    xsi_set_current_line(66, ng0);
    t77 = (t0 + 1656);
    xsi_set_assignedflag(t77);
    t78 = (t0 + 4208);
    *((int *)t78) = 1;
    NetReassign_66_4(t0);
    goto LAB87;

LAB88:    xsi_set_current_line(70, ng0);

LAB91:    xsi_set_current_line(71, ng0);
    t19 = ((char*)((ng1)));
    t20 = (t0 + 1472);
    xsi_vlogvar_wait_assign_value(t20, t19, 0, 0, 1, 0LL);
    xsi_set_current_line(72, ng0);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB92;

LAB93:    xsi_set_current_line(79, ng0);

LAB103:    xsi_set_current_line(80, ng0);
    t2 = (t0 + 1380);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = (t0 + 1288);
    t19 = (t5 + 36U);
    t20 = *((char **)t19);
    t7 = *((unsigned int *)t4);
    t8 = *((unsigned int *)t20);
    t9 = (t7 | t8);
    *((unsigned int *)t6) = t9;
    t26 = (t4 + 4);
    t27 = (t20 + 4);
    t29 = (t6 + 4);
    t10 = *((unsigned int *)t26);
    t11 = *((unsigned int *)t27);
    t12 = (t10 | t11);
    *((unsigned int *)t29) = t12;
    t13 = *((unsigned int *)t29);
    t14 = (t13 != 0);
    if (t14 == 1)
        goto LAB104;

LAB105:
LAB106:    t32 = (t6 + 4);
    t42 = *((unsigned int *)t32);
    t43 = (~(t42));
    t58 = *((unsigned int *)t6);
    t59 = (t58 & t43);
    t60 = (t59 != 0);
    if (t60 > 0)
        goto LAB107;

LAB108:
LAB109:
LAB94:    goto LAB90;

LAB92:    xsi_set_current_line(72, ng0);

LAB95:    xsi_set_current_line(73, ng0);
    t4 = (t0 + 1380);
    t5 = (t4 + 36U);
    t19 = *((char **)t5);
    t20 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 32, t19, 8, t20, 32);
    t26 = (t0 + 1380);
    xsi_vlogvar_wait_assign_value(t26, t6, 0, 0, 8, 0LL);
    xsi_set_current_line(74, ng0);
    t2 = (t0 + 1380);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t19 = (t4 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (t7 >> 0);
    t9 = (t8 & 1);
    *((unsigned int *)t6) = t9;
    t10 = *((unsigned int *)t19);
    t11 = (t10 >> 0);
    t12 = (t11 & 1);
    *((unsigned int *)t5) = t12;
    t20 = (t0 + 1380);
    t26 = (t20 + 36U);
    t27 = *((char **)t26);
    memset(t28, 0, 8);
    t29 = (t28 + 4);
    t30 = (t27 + 4);
    t13 = *((unsigned int *)t27);
    t14 = (t13 >> 3);
    t15 = (t14 & 1);
    *((unsigned int *)t28) = t15;
    t16 = *((unsigned int *)t30);
    t17 = (t16 >> 3);
    t18 = (t17 & 1);
    *((unsigned int *)t29) = t18;
    t21 = *((unsigned int *)t6);
    t22 = *((unsigned int *)t28);
    t23 = (t21 & t22);
    *((unsigned int *)t34) = t23;
    t31 = (t6 + 4);
    t32 = (t28 + 4);
    t33 = (t34 + 4);
    t24 = *((unsigned int *)t31);
    t25 = *((unsigned int *)t32);
    t39 = (t24 | t25);
    *((unsigned int *)t33) = t39;
    t40 = *((unsigned int *)t33);
    t41 = (t40 != 0);
    if (t41 == 1)
        goto LAB96;

LAB97:
LAB98:    t37 = (t34 + 4);
    t74 = *((unsigned int *)t37);
    t75 = (~(t74));
    t76 = *((unsigned int *)t34);
    t81 = (t76 & t75);
    t82 = (t81 != 0);
    if (t82 > 0)
        goto LAB99;

LAB100:
LAB101:    goto LAB94;

LAB96:    t42 = *((unsigned int *)t34);
    t43 = *((unsigned int *)t33);
    *((unsigned int *)t34) = (t42 | t43);
    t35 = (t6 + 4);
    t36 = (t28 + 4);
    t58 = *((unsigned int *)t6);
    t59 = (~(t58));
    t60 = *((unsigned int *)t35);
    t61 = (~(t60));
    t62 = *((unsigned int *)t28);
    t63 = (~(t62));
    t64 = *((unsigned int *)t36);
    t65 = (~(t64));
    t79 = (t59 & t61);
    t80 = (t63 & t65);
    t66 = (~(t79));
    t67 = (~(t80));
    t68 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t68 & t66);
    t69 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t69 & t67);
    t72 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t72 & t66);
    t73 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t73 & t67);
    goto LAB98;

LAB99:    xsi_set_current_line(74, ng0);

LAB102:    xsi_set_current_line(75, ng0);
    t38 = ((char*)((ng1)));
    t44 = (t0 + 1380);
    xsi_vlogvar_wait_assign_value(t44, t38, 0, 0, 8, 0LL);
    xsi_set_current_line(76, ng0);
    t2 = (t0 + 1288);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 32, t4, 8, t5, 32);
    t19 = (t0 + 1288);
    xsi_vlogvar_wait_assign_value(t19, t6, 0, 0, 8, 0LL);
    goto LAB101;

LAB104:    t15 = *((unsigned int *)t6);
    t16 = *((unsigned int *)t29);
    *((unsigned int *)t6) = (t15 | t16);
    t30 = (t4 + 4);
    t31 = (t20 + 4);
    t17 = *((unsigned int *)t30);
    t18 = (~(t17));
    t21 = *((unsigned int *)t4);
    t79 = (t21 & t18);
    t22 = *((unsigned int *)t31);
    t23 = (~(t22));
    t24 = *((unsigned int *)t20);
    t80 = (t24 & t23);
    t25 = (~(t79));
    t39 = (~(t80));
    t40 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t40 & t25);
    t41 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t41 & t39);
    goto LAB106;

LAB107:    xsi_set_current_line(81, ng0);
    t33 = (t0 + 1380);
    t35 = (t33 + 36U);
    t36 = *((char **)t35);
    t37 = ((char*)((ng1)));
    memset(t28, 0, 8);
    t38 = (t36 + 4);
    t44 = (t37 + 4);
    t61 = *((unsigned int *)t36);
    t62 = *((unsigned int *)t37);
    t63 = (t61 ^ t62);
    t64 = *((unsigned int *)t38);
    t65 = *((unsigned int *)t44);
    t66 = (t64 ^ t65);
    t67 = (t63 | t66);
    t68 = *((unsigned int *)t38);
    t69 = *((unsigned int *)t44);
    t72 = (t68 | t69);
    t73 = (~(t72));
    t74 = (t67 & t73);
    if (t74 != 0)
        goto LAB113;

LAB110:    if (t72 != 0)
        goto LAB112;

LAB111:    *((unsigned int *)t28) = 1;

LAB113:    t47 = (t28 + 4);
    t75 = *((unsigned int *)t47);
    t76 = (~(t75));
    t81 = *((unsigned int *)t28);
    t82 = (t81 & t76);
    t83 = (t82 != 0);
    if (t83 > 0)
        goto LAB114;

LAB115:    xsi_set_current_line(87, ng0);
    t2 = (t0 + 1380);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_minus(t6, 32, t4, 8, t5, 32);
    t19 = (t0 + 1380);
    xsi_vlogvar_wait_assign_value(t19, t6, 0, 0, 8, 0LL);

LAB116:    goto LAB109;

LAB112:    t45 = (t28 + 4);
    *((unsigned int *)t28) = 1;
    *((unsigned int *)t45) = 1;
    goto LAB113;

LAB114:    xsi_set_current_line(81, ng0);

LAB117:    xsi_set_current_line(82, ng0);
    t48 = (t0 + 1288);
    t49 = (t48 + 36U);
    t50 = *((char **)t49);
    t51 = ((char*)((ng3)));
    memset(t34, 0, 8);
    xsi_vlog_unsigned_minus(t34, 32, t50, 8, t51, 32);
    t52 = (t0 + 1288);
    xsi_vlogvar_wait_assign_value(t52, t34, 0, 0, 8, 0LL);
    xsi_set_current_line(83, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1380);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 0LL);
    goto LAB116;

}

static void NetReassign_28_2(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 2468U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(28, ng0);
    t3 = 0;
    t2 = ((char*)((ng1)));
    t4 = (t0 + 4200);
    if (*((int *)t4) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 1656);
    xsi_vlogvar_assignassignvalue(t5, t2, 0, 0, 0, 32, ((int*)(t4)));
    t3 = 1;
    goto LAB5;

}

static void NetReassign_33_3(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 2612U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(33, ng0);
    t3 = 0;
    t2 = ((char*)((ng3)));
    t4 = (t0 + 4204);
    if (*((int *)t4) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 1656);
    xsi_vlogvar_assignassignvalue(t5, t2, 0, 0, 0, 32, ((int*)(t4)));
    t3 = 1;
    goto LAB5;

}

static void NetReassign_66_4(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 2756U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(66, ng0);
    t3 = 0;
    t2 = ((char*)((ng3)));
    t4 = (t0 + 4208);
    if (*((int *)t4) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 1656);
    xsi_vlogvar_assignassignvalue(t5, t2, 0, 0, 0, 32, ((int*)(t4)));
    t3 = 1;
    goto LAB5;

}


extern void work_m_00000000000253946563_1338705563_init()
{
	static char *pe[] = {(void *)Initial_18_0,(void *)Always_27_1,(void *)NetReassign_28_2,(void *)NetReassign_33_3,(void *)NetReassign_66_4};
	xsi_register_didat("work_m_00000000000253946563_1338705563", "isim/Board232_isim_beh.exe.sim/work/m_00000000000253946563_1338705563.didat");
	xsi_register_executes(pe);
}
