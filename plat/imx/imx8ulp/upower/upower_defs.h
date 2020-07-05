/* SPDX-License-Identifier: BSD-3-Clause */
/* +FHDR------------------------------------------------------------------------
 * Copyright (c) 2019, 2020 NXP Semiconductor N.V.
 * -----------------------------------------------------------------------------
 * FILE NAME      : upower_defs.h
 * DEPARTMENT     : BSTC - Campinas, Brazil
 * AUTHOR         : Celso Brites
 * AUTHOR'S EMAIL : celso.brites@nxp.com
 * -----------------------------------------------------------------------------
 * RELEASE HISTORY
 * VERSION DATE        AUTHOR                  DESCRIPTION
 *
 * $Log: upower_defs.h.rca $
 * 
 *  Revision: 1.197 Mon Nov  9 14:39:19 2020 nxf42682
 *  powersys_fw_048.011.010.005
 * 
 *  Revision: 1.62 Mon Nov  9 08:09:16 2020 nxa11511
 *  *** empty comment string ***
 * 
 *  Revision: 1.61 Wed Nov  4 15:38:26 2020 nxa11511
 *  start response message now returns major, minor and fixes version numbers, no longer soc.
 *  Adds vfixes to typedef upwr_code_vers_t;
 *  Init message soc field reduced to 7 bits, major increased to 5.
 *  Init message now has explict field for fixes number.
 * 
 *  Revision: 1.60 Fri Oct 23 11:49:56 2020 nxa11511
 *  Deleted the GPL license statements, leaving only BSD, as it is compatible with Linux and good for closed ROM/firmware code.
 * 
 *  Revision: 1.59 Wed Sep 30 15:57:35 2020 nxa11511
 *  Now UPWR_DGN_MAX = UPWR_DGN_ALL.
 *  Redefines upwr_dgn_log_t according to dgn_lib.S;
 *  Merge from branch dgn_lib.
 * 
 *  Revision: 1.58.1.1 Tue Sep 29 10:07:12 2020 nxa11511
 *  Adds UPWR_DGN_ALL to upwr_dgn_mode_t, which is now also UPWR_DGN_MAX.
 *  In upwr_dgn_log_t, DGN_LOG_EVENTNEW added DGN_LOG_SPARE deleted.
 * 
 *  Revision: 1.49 Mon Jun  8 06:46:30 2020 nxa11511
 *  *** empty comment string ***
 * 
 *  Revision: 1.44 Tue Apr  7 13:34:01 2020 nxf42682
 *  Put TYPES_LOCAL_H - fixed serious compilation error of version 1.42 and 1.43
 * 
 *  Revision: 1.43 Tue Mar 31 12:50:46 2020 nxf42682
 *  Merged version 1.42 with 1.41.1.1
 * 
 *  Revision: 1.42 Tue Mar 31 08:06:59 2020 nxa11511
 *  Fixes a compiling error.
 * 
 *  Revision: 1.41 Mon Mar 30 23:07:26 2020 nxa10721
 *  Added support for AVD bias
 * 
 *  Revision: 1.40 Mon Mar 30 14:29:44 2020 nxa11511
 *  Updates to API spec 20200404:
 *  API functions upwr_power_on and upwr_boot_start deleted.
 *  API functions upwr_xcp_power_on and upwr_xcp_boot_start moved to the Power Management service group;
 *  renamed to upwr_pwm_dom_power_on and upwr_pwm_boot_start
 * 
 *  Revision: 1.39 Fri Mar 27 17:17:34 2020 nxa11511
 *  Adds typedef upwr_start_msg.
 *  (sets new typedef upwr_xcp_start_msg;
 *  Adds typedef upwr_resp_msg upwr_shutdown_msg;
 *
 *  Revision: 1.35 Tue Mar 10 06:24:09 2020 nxa11511
 *  Fixes identations to comply with the Linux kernel coding guidelines.
 * 
 *  Revision: 1.34 Thu Mar  5 22:08:03 2020 nxa10721
 *  Using the RTD monitor config also for APD
 * 
 *  Revision: 1.33 Mon Mar  2 12:16:14 2020 nxa11511
 *  Changes typedef upwr_start_msg to simple 1-word message.
 * 
 *  Revision: 1.29 Mon Feb 10 10:34:29 2020 nxa10721
 *  Temporarily turns RTD config pointers as uint32_t for A35 compilation in SoC
 * 
 *  Revision: 1.28 Sun Feb  9 16:10:01 2020 nxa10721
 *  Added abs_pwr_mode_t, solving TKT0532383
 *  Define RTD swt and mem configs as a pointer or 32-bit word, according to CPU
 * 
 *  Revision: 1.27 Thu Jan 30 07:09:03 2020 nxa11511
 *  typedef upwr_rom_vers_t members major and minor renamed to vmajor and vminor to avoid clashing with a Linux include macro.
 * 
 *  Revision: 1.23 Mon Nov 25 10:38:33 2019 nxa10721
 *  Typecastings to reduce warns
 * 
 *  Revision: 1.21 Wed Nov 13 21:59:44 2019 nxa10721
 *  Added toutines to handle swt offset
 * 
 *  Revision: 1.20 Tue Nov  5 12:46:45 2019 nxa10721
 *  Added APD power mode config structs, using offsets instead of pointers
 * 
 *  Revision: 1.19 Thu Oct 24 11:33:48 2019 nxa10721
 *  Remove some g++ warns on strings
 * 
 *  Revision: 1.18 Fri Oct 18 06:42:40 2019 nxa10721
 *  Added APD and core power modes
 * 
 *  Revision: 1.17 Wed Oct  9 11:35:24 2019 nxa13158
 *  replaced powersys low power mode config by struct config
 * 
 *  Revision: 1.16 Tue Sep 24 12:16:30 2019 nxa13158
 *  updated upwr_pmc_mon_rtd_cfg_t struct (removed unecessary union)
 * 
 *  Revision: 1.15 Mon Aug 26 14:24:26 2019 nxa13158
 *  reorganized power modes enum to make easy to reuse in tb
 * 
 *  Revision: 1.14 Fri Aug 23 17:54:11 2019 nxa11511
 *  Renames UPWR_RESP_NOT_IMPL to UPWR_RESP_UNINSTALLD.
 * 
 *  Revision: 1.13 Wed Aug 21 12:59:15 2019 nxa13158
 *  renamed RTD mode to active DMA, moved pmc_bias_mode_t to
 *  pmc_api. Updated mem bias struct config
 * 
 *  Revision: 1.12 Wed Aug 21 07:01:47 2019 nxa11511
 *  Several changes in message formats.
 * 
 *  Revision: 1.9 Thu Aug 15 17:10:04 2019 nxa13158
 *  removed POR from power modes transitions. Not needed anymore
 * 
 *  Revision: 1.8 Thu Aug 15 11:50:08 2019 nxa11511
 *  UPWR_SG_PMODE renamed to UPWR_SG_PMGMT.
 * 
 *  Revision: 1.7 Wed Aug 14 10:16:48 2019 nxa13158
 *  Fixed upwr_pmc_bias_cfg_t struct definition
 * 
 *  Revision: 1.6 Tue Aug 13 17:52:07 2019 nxa11511
 *  Adds Exception function enum.
 *  Fixes union upwr_pmc_mon_rtd_cfg_t.
 * 
 *  Revision: 1.5 Tue Aug 13 15:26:40 2019 nxa13158
 *  added Power Modes configuration structs.
 * 
 *  Revision: 1.4 Mon Aug 12 18:18:40 2019 nxa11511
 *  Message structs/unions turned into typedefs.
 *  Adds message formats for the new initialization procedure with the boot start step.
 * 
 *  Revision: 1.3 Sat Aug 10 09:06:21 2019 nxa11511
 *  Adds extern "C" if __cplusplus is #defined and UPWR_NAMESPACE is #undefined.
 * 
 *  Revision: 1.1 Thu Aug  1 17:14:33 2019 nxa11511
 *  uPower driver API #defines and typedefs shared with the firmware
 * 
 * -----------------------------------------------------------------------------
 * KEYWORDS: micro-power uPower driver API
 * -----------------------------------------------------------------------------
 * PURPOSE: uPower driver API #defines and typedefs shared with the firmware
 * -----------------------------------------------------------------------------
 * PARAMETERS:
 * PARAM NAME RANGE:DESCRIPTION:       DEFAULTS:                           UNITS
 * -----------------------------------------------------------------------------
 * REUSE ISSUES: no reuse issues
 * -FHDR--------------------------------------------------------------------- */

#ifndef _UPWR_DEFS_H
#define _UPWR_DEFS_H

#ifndef TYPES_LOCAL_H 

#include <stdint.h> /* this include breaks the SoC compile - TBD why? */

#endif /* not production code */

#ifndef UPWR_PMC_SWT_WORDS
#define UPWR_PMC_SWT_WORDS              (1)
#endif

#ifndef UPWR_PMC_MEM_WORDS
#define UPWR_PMC_MEM_WORDS              (2)
#endif

/* ****************************************************************************
 * DOWNSTREAM MESSAGES - COMMANDS/FUNCTIONS
 * ****************************************************************************
 */

#define UPWR_SRVGROUP_BITS  (4)
#define UPWR_FUNCTION_BITS  (4)
#define UPWR_PWDOMAIN_BITS  (4)
#define UPWR_HEADER_BITS   \
                      (UPWR_SRVGROUP_BITS+UPWR_FUNCTION_BITS+UPWR_PWDOMAIN_BITS)
#define UPWR_ARG_BITS      (32-UPWR_HEADER_BITS)
#if   ((UPWR_ARG_BITS & 1) > 0)
#error "UPWR_ARG_BITS must be an even number"
#endif
#define UPWR_ARG64_BITS          (64-UPWR_HEADER_BITS)
#define UPWR_HALF_ARG_BITS       (UPWR_ARG_BITS >> 1)
#define UPWR_DUAL_OFFSET_BITS    ((UPWR_ARG_BITS+32) >> 1)

#ifdef  __cplusplus
#ifndef UPWR_NAMESPACE /* extern "C" 'cancels' the effect of namespace */
extern "C" {
#endif
#endif

/* message header: header fields common to all downstream messages.
 */

struct upwr_msg_hdr {
	uint32_t domain   :UPWR_PWDOMAIN_BITS;           /* power domain */
	uint32_t srvgrp   :UPWR_SRVGROUP_BITS;          /* service group */
	uint32_t function :UPWR_FUNCTION_BITS;             /* function */
	uint32_t arg      :UPWR_ARG_BITS;     /* function-specific argument */
};

/* generic 1-word downstream message format */

typedef union {
	struct upwr_msg_hdr  hdr;
	uint32_t             word;  /* message first word */
} upwr_down_1w_msg;

/* generic 2-word downstream message format */

typedef struct {
	struct upwr_msg_hdr  hdr;
	uint32_t             word2;  /* message second word */
} upwr_down_2w_msg;

/* message format for functions that receive a pointer/offset */

typedef struct {
	struct upwr_msg_hdr  hdr;
	uint32_t             ptr; /* config struct offset */
} upwr_pointer_msg;

/* message format for functions that receive 2 pointers/offsets */

typedef union {
	struct upwr_msg_hdr  hdr;
	struct {
		uint64_t :UPWR_HEADER_BITS;
		uint64_t ptr0:UPWR_DUAL_OFFSET_BITS;
		uint64_t ptr1:UPWR_DUAL_OFFSET_BITS;
	} ptrs;
} upwr_2pointer_msg;

typedef enum { /* Service Groups in priority order, high to low */
	UPWR_SG_EXCEPT,   /* 0 = exception           */
	UPWR_SG_PWRMGMT , /* 1 = power management    */
	UPWR_SG_DELAYM,   /* 2 = delay   measurement */
	UPWR_SG_VOLTM ,   /* 3 = voltage measurement */
	UPWR_SG_CURRM,    /* 4 = current measurement */
	UPWR_SG_TEMPM,    /* 5 = temperature measurement */
	UPWR_SG_DIAG,     /* 6 = diagnostic  */
	UPWR_SG_COUNT
} upwr_sg_t;

/* *************************************************************************
 * Initialization - downstream
 ***************************************************************************/

typedef upwr_down_1w_msg upwr_start_msg; /* start command message */

typedef upwr_down_1w_msg upwr_power_on_msg;   /* power on   command message */
typedef upwr_down_1w_msg upwr_boot_start_msg; /* boot start command message */

typedef union {
	struct upwr_msg_hdr hdr;
	upwr_power_on_msg   power_on;
	upwr_boot_start_msg boot_start;
	upwr_start_msg      start;
} upwr_startup_down_msg;

/* *************************************************************************
 * Service Group EXCEPTION - downstream
 ***************************************************************************/

typedef enum {             /* Exception Functions */
	UPWR_XCP_INIT,     /* 0 = init msg (not a service request itself) */
	UPWR_XCP_PING = UPWR_XCP_INIT,
			   /*  0 = also ping request, since its response is
				   an init msg */
	UPWR_XCP_START,    /*  1 = service start: upwr_start 
                            *      (not a service request itself) */
	UPWR_XCP_SHUTDOWN, /*  2 = service shutdown: upwr_xcp_shutdown */
	UPWR_XCP_CONFIG,   /*  3 = uPower configuration: upwr_xcp_config */
	UPWR_XCP_SW_ALARM, /*  4 = uPower soft alarm: upwr_xcp_sw_alarm */
	UPWR_XCP_SPARE_5,  /*  5 = spare */
	UPWR_XCP_SPARE_6,  /*  6 = spare */
	UPWR_XCP_SPARE_7,  /*  7 = spare */
	UPWR_XCP_SPARE_8,  /*  8 = spare */
	UPWR_XCP_SPARE_9,  /*  9 = spare */
	UPWR_XCP_SPARE_10, /* 10 = spare */
	UPWR_XCP_SPARE_11, /* 11 = spare */
	UPWR_XCP_SPARE_12, /* 12 = spare */
	UPWR_XCP_SPARE_13, /* 13 = spare */
	UPWR_XCP_SPARE_14, /* 14 = spare */
	UPWR_XCP_SPARE_15, /* 15 = spare */
	UPWR_XCP_F_COUNT
} upwr_xcp_f_t;

typedef upwr_down_1w_msg    upwr_xcp_ping_msg;
typedef upwr_down_1w_msg    upwr_xcp_shutdown_msg;
typedef upwr_power_on_msg   upwr_xcp_power_on_msg;
typedef upwr_boot_start_msg upwr_xcp_boot_start_msg;
typedef upwr_start_msg      upwr_xcp_start_msg;
typedef upwr_down_2w_msg    upwr_xcp_config_msg;
typedef upwr_down_1w_msg    upwr_xcp_swalarm_msg;

/* Exception all messages */

typedef union {
        struct upwr_msg_hdr       hdr;       /* message header */
	upwr_xcp_ping_msg         ping;      /* ping */
        upwr_xcp_start_msg        start;     /* service start */
	upwr_xcp_shutdown_msg     shutdown;  /* shutdown */
	upwr_xcp_boot_start_msg   bootstart; /* boot start */
	upwr_xcp_config_msg       config;    /* uPower configuration */
	upwr_xcp_swalarm_msg      swalarm;   /* software alarm */
} upwr_xcp_msg;

/* *************************************************************************
 * Service Group POWER MAMANGEMENT - downstream
 ***************************************************************************/

typedef enum {            /* Power Management Functions */
	UPWR_PWM_DEVMODE, /* 0 = device mode change/config */
	UPWR_PWM_VOLT   , /* 1 = voltage change: upwr_pwm_chng_reg_voltage */
	UPWR_PWM_SWITCH , /* 2 = switch control: upwr_pwm_chng_switch_mem */
	UPWR_PWM_PWR_ON,  /* 3 = switch/RAM/ROM power on: upwr_pwm_power_on  */
	UPWR_PWM_PWR_OFF, /* 4 = switch/RAM/ROM power off: upwr_pwm_power_off */
	UPWR_PWM_RETAIN,  /* 5 = retain memory array: upwr_pwm_mem_retain */
	UPWR_PWM_DOM_BIAS,/* 6 = Domain bias control: upwr_pwm_chng_dom_bias */
	UPWR_PWM_MEM_BIAS,/* 7 = Memory bias control: upwr_pwm_chng_mem_bias */
	UPWR_PWM_PMICMOD, /* 8 = PMIC mode pins control */
	UPWR_PWM_PES,     /* 9 = Power Event Sequencer */
	UPWR_PWM_CONFIG , /* 10= apply power mode defined configuration */
	UPWR_PWM_CFGPTR,  /* 11= configuration pointer */
	UPWR_PWM_DOM_PWRON,/* 12 = domain power on: upwr_pwm_dom_power_on */
	UPWR_PWM_BOOT,     /* 13 = boot start: upwr_pwm_boot_start */
        UPWR_PWM_FREQ,     /* 14 = domain frequency setup */
	UPWR_PWM_PARAM,    /* 15 = power management parameters */
	UPWR_PWM_F_COUNT
} upwr_pwm_f_t;

struct upwr_switch_board_t { /* set of 32 switches */
	uint32_t on;   /* Switch on state,   1 bit per instance */
	uint32_t mask; /* actuation mask, 1 bit per instance */
                       /* (bit = 1 applies on bit) */
};

struct upwr_mem_switches_t { /* set of 32 RAM/ROM switches */
	uint32_t array;   /* RAM/ROM array state,      1 bit per instance */
	uint32_t perif;   /* RAM/ROM peripheral state, 1 bit per instance */
	uint32_t mask;    /* actuation mask,       1 bit per instance */
                          /* (bit = 1 applies on bit) */
};

typedef upwr_down_1w_msg upwr_pwm_dom_pwron_msg;  /* domain power on message */
typedef upwr_down_1w_msg upwr_pwm_boot_start_msg; /* boot start      message */


/* functions with complex arguments use the pointer message formats: */

typedef upwr_pointer_msg upwr_pwm_retain_msg;
typedef upwr_pointer_msg upwr_pwm_pmode_cfg_msg;

#define UPWR_DOMBIAS_MODE_BITS    (4)
#define UPWR_DOMBIAS_RBB_BITS     ((UPWR_ARG_BITS - UPWR_DOMBIAS_MODE_BITS)/2)
#if   ((UPWR_ARG_BITS - UPWR_DOMBIAS_MODE_BITS) & 1) != 0
#error "UPWR_ARG_BITS - UPWR_DOMBIAS_MODE_BITS must be an even number"
#endif

typedef union {
	struct upwr_msg_hdr       hdr;       /* message header */
	struct {
		uint32_t rsv :UPWR_HEADER_BITS;
		uint32_t mode:UPWR_DOMBIAS_MODE_BITS;
		uint32_t rbbn:UPWR_DOMBIAS_RBB_BITS;/* rev. back bias N-well */
		uint32_t rbbp:UPWR_DOMBIAS_RBB_BITS;/* rev. back bias P-well */
	} args;
} upwr_pwm_dom_bias_msg;

typedef upwr_down_1w_msg upwr_pwm_mem_bias_msg;

typedef upwr_pointer_msg upwr_pwm_pes_seq_msg;

/* upwr_pwm_devmode-specific message format */

typedef union {
	struct upwr_msg_hdr hdr;
	struct {
		uint32_t rsv :UPWR_HEADER_BITS;
		uint32_t dev :UPWR_HALF_ARG_BITS;  /* device id */
		uint32_t mode:UPWR_HALF_ARG_BITS;  /* mode */
	} args;
} upwr_pwm_devmode_msg ;

/* upwr_pwm_volt-specific message format */

typedef union {
	struct upwr_msg_hdr hdr;
	struct {
		uint32_t rsv:UPWR_HEADER_BITS;
		uint32_t reg:UPWR_HALF_ARG_BITS;  /* regulator id  */
		uint32_t volt:UPWR_HALF_ARG_BITS; /* voltage value */
	} args;
} upwr_pwm_volt_msg;

/* upwr_pwm_freq_setup-specific message format */

typedef union {
	struct upwr_msg_hdr hdr;
	struct {
		uint32_t rsv:UPWR_HEADER_BITS;
		uint32_t nextfq:UPWR_HALF_ARG_BITS; /* next    frequency  */
		uint32_t currfq:UPWR_HALF_ARG_BITS; /* current frequency */
	} args;
} upwr_pwm_freq_msg;

typedef upwr_down_2w_msg upwr_pwm_param_msg;

/* upwr_pwm_pmicmod-specific message format */

typedef union {
	struct upwr_msg_hdr hdr;
	struct {
		uint32_t rsv:UPWR_HEADER_BITS;
		uint32_t value:UPWR_HALF_ARG_BITS;  /* value  */
		uint32_t mask:UPWR_HALF_ARG_BITS;   /* pin mask */
	} args;
} upwr_pwm_pmicmod_msg;

/* functions that pass a pointer use message format upwr_pointer_msg */

typedef upwr_pointer_msg upwr_pwm_cfgptr_msg;

/* functions that pass 2 pointers use message format upwr_2pointer_msg
 */

typedef upwr_2pointer_msg upwr_pwm_switch_msg;
typedef upwr_2pointer_msg upwr_pwm_pwron_msg;
typedef upwr_2pointer_msg upwr_pwm_pwroff_msg;

/* Power Management all messages */

typedef union {
	struct upwr_msg_hdr     hdr;      /* message header */
	upwr_pwm_param_msg      param;    /* power management parameters */
	upwr_pwm_dom_bias_msg   dom_bias; /* domain bias message */
	upwr_pwm_mem_bias_msg   mem_bias; /* memory bias message */
	upwr_pwm_pes_seq_msg    pes;      /* PE seq. message */
	upwr_pwm_pmode_cfg_msg  pmode;    /* power mode config message */
	upwr_pwm_devmode_msg    devmode;  /* define mode message */
	upwr_pwm_volt_msg       volt;     /* set voltage message */
	upwr_pwm_freq_msg       freq;     /* set frequency message */
	upwr_pwm_pmicmod_msg    pmicmod;  /* PMIC mode message */
	upwr_pwm_switch_msg     switches; /* switch control message */
	upwr_pwm_pwron_msg      pwron;    /* switch/RAM/ROM power on  message */
	upwr_pwm_pwroff_msg     pwroff;   /* switch/RAM/ROM power off message */
	upwr_pwm_retain_msg     retain;   /* memory retain message */
	upwr_pwm_cfgptr_msg     cfgptr;   /* configuration pointer message*/
	upwr_pwm_dom_pwron_msg  dompwron; /* domain power on message */
	upwr_pwm_boot_start_msg boot;     /* boot start      message */
} upwr_pwm_msg;

typedef upwr_down_2w_msg upwr_down_max_msg; /* longest downstream msg */

/* Domain Bias config (one per domain) */

struct upwr_dom_bias_cfg_t {
	uint32_t mode; /* Domain bias mode config */
	uint32_t rbbn; /* reverse back bias N well */
	uint32_t rbbp; /* reverse back bias P well */
};

/* AVD mode and voltage level */

typedef union {
	uint32_t                  R;
	struct {
		uint32_t                  mode      : 8;    /* Dom bias mode */
		uint32_t                  rsrv_1    : 8;
		uint32_t                  avd_mode  : 8;    /* AVD bias mode */
		uint32_t                  rsrv_2    : 8;
	}                         B;
} dom_bias_mode_cfg_t;

typedef union {
	uint32_t                  R;
	struct {
		uint32_t                  lvl       : 8;    /* Dom bias level */
		uint32_t                  rsrv_1    : 8;
		uint32_t                  avd_lvl   : 8;    /* AVD bias level */
		uint32_t                  rsrv_2    : 8;
	}                         B;
} dom_bias_lvl_cfg_t;

/* Extract AVD bias config from a domain bias config */
static inline struct upwr_dom_bias_cfg_t *get_avd_dom_bias_cfg(
	struct upwr_dom_bias_cfg_t *dom_bias_cfg, 
	struct upwr_dom_bias_cfg_t *avd_bias_cfg
)
{
	dom_bias_mode_cfg_t       dom_bias_mode;
	dom_bias_lvl_cfg_t        dom_bias_lvl;
	dom_bias_mode.R = dom_bias_cfg->mode;
	avd_bias_cfg->mode = dom_bias_mode.B.avd_mode;
	dom_bias_lvl.R  = dom_bias_cfg->rbbn;
	avd_bias_cfg->rbbn = dom_bias_lvl.B.avd_lvl;
	dom_bias_lvl.R  = dom_bias_cfg->rbbp;
	avd_bias_cfg->rbbp = dom_bias_lvl.B.avd_lvl;
	return avd_bias_cfg;
}

/* Memory Bias config */

struct upwr_mem_bias_cfg_t {
	uint32_t en; /* Memory bias enable config */
};

/* all configs in Power Management services */

typedef union {
	struct upwr_switch_board_t     switch_board;
	struct upwr_mem_switches_t     mem_switches;
	struct upwr_dom_bias_cfg_t     dom_bias;
	struct upwr_mem_bias_cfg_t     mem_bias;
} upwr_pwm_srv_cfg_t;

/* Split different Bias */

struct upwr_pmc_bias_cfg_t {
	struct upwr_dom_bias_cfg_t dombias_cfg; /* Domain Bias config */
	struct upwr_mem_bias_cfg_t membias_cfg; /* Memory Bias config */
};

/* PowerSys low power config */

struct upwr_powersys_cfg_t {
	uint32_t lpm_mode; /* Powersys low power mode */
};

/* Power and mem switches */
typedef struct {
	volatile struct upwr_switch_board_t  swt_board[UPWR_PMC_SWT_WORDS];
	volatile struct upwr_mem_switches_t  swt_mem  [UPWR_PMC_MEM_WORDS]  ;
} swt_config_t;

/* *************************************************************************
 * Service Group DIAGNOSE - downstream
 ***************************************************************************/

typedef enum {            /* Diagnose Functions */
	UPWR_DGN_MODE,    /* 0 = diagnose mode: upwr_dgn_mode */
	UPWR_DGN_F_COUNT
} upwr_dgn_f_t;

typedef enum {
	UPWR_DGN_ALL2ERR, /* record all until an error occurs,
			     freeze recording on error             */
	UPWR_DGN_ALL2HLT, /* record all until an error occurs,
			     halt core        on error             */
	UPWR_DGN_ALL,     /* trace, warnings, errors, task state recorded */
	UPWR_DGN_MAX = UPWR_DGN_ALL,
	UPWR_DGN_TRACE,   /* trace, warnings, errors recorded      */
	UPWR_DGN_SRVREQ,  /* service request activity recorded     */
	UPWR_DGN_WARN,    /* warnings and errors recorded          */
	UPWR_DGN_ERROR,   /* only errors recorded                  */
	UPWR_DGN_NONE,    /* no diagnostic recorded                */
	UPWR_DGN_COUNT
} upwr_dgn_mode_t;

typedef upwr_down_1w_msg upwr_dgn_mode_msg;

typedef union {
	struct upwr_msg_hdr   hdr;
	upwr_dgn_mode_msg     mode_msg;
} upwr_dgn_msg;

/* diagnostics log types in the shared RAM log buffer */

typedef enum {
	DGN_LOG_NONE       =   0x00000000,
	DGN_LOG_INFO       =   0x10000000,
	DGN_LOG_ERROR      =   0x20000000,
	DGN_LOG_ASSERT     =   0x30000000,
	DGN_LOG_EXCEPT     =   0x40000000,
	DGN_LOG_EVENT      =   0x50000000, // old event trace
	DGN_LOG_EVENTNEW   =   0x60000000, // new event trace
	DGN_LOG_SERVICE    =   0x70000000,
	DGN_LOG_TASKDEF    =   0x80000000,
	DGN_LOG_TASKEXE    =   0x90000000,
	DGN_LOG_MUTEX      =   0xA0000000,
	DGN_LOG_SEMAPH     =   0xB0000000,
	DGN_LOG_TIMER      =   0xC0000000,
	DGN_LOG_CALLTRACE  =   0xD0000000,
	DGN_LOG_DATA       =   0xE0000000,
	DGN_LOG_PCTRACE    =   0xF0000000
} upwr_dgn_log_t;

/* ****************************************************************************
 * UPSTREAM MESSAGES - RESPONSES
 * ****************************************************************************
 */

/* generic ok/ko response message */

#define UPWR_RESP_ERR_BITS (4)
#define UPWR_RESP_HDR_BITS (UPWR_RESP_ERR_BITS+\
                            UPWR_SRVGROUP_BITS+UPWR_FUNCTION_BITS)
#define UPWR_RESP_RET_BITS (32-UPWR_RESP_HDR_BITS)

typedef enum { /* response error codes */
	UPWR_RESP_OK = 0,     /* no error */
	UPWR_RESP_SG_BUSY,    /* service group is busy */
	UPWR_RESP_SHUTDOWN,   /* services not up or shutting down */
	UPWR_RESP_BAD_REQ,    /* invalid request */
	UPWR_RESP_BAD_STATE,  /* system state doesn't allow perform the request */
	UPWR_RESP_UNINSTALLD, /* service or function not installed */
	UPWR_RESP_UNINSTALLED =
	UPWR_RESP_UNINSTALLD, /* service or function not installed (alias) */
	UPWR_RESP_RESOURCE,   /* resource not available */
	UPWR_RESP_TIMEOUT,    /* service timeout */
	UPWR_RESP_COUNT
} upwr_resp_t;

struct upwr_resp_hdr {
	uint32_t errcode :UPWR_RESP_ERR_BITS;
	uint32_t srvgrp  :UPWR_SRVGROUP_BITS;      /* service group */
	uint32_t function:UPWR_FUNCTION_BITS;
	uint32_t ret     :UPWR_RESP_RET_BITS;      /* return value, if any */
};

/* generic 1-word upstream message format */

typedef union {
	struct upwr_resp_hdr hdr;
	uint32_t             word;
} upwr_resp_msg;

/* generic 2-word upstream message format */

typedef struct {
	struct upwr_resp_hdr   hdr;
	uint32_t               word2;  /* message second word */
} upwr_up_2w_msg;

typedef upwr_up_2w_msg   upwr_up_max_msg;

/* *************************************************************************
 * Exception/Initialization - upstream
 ***************************************************************************/

#define UPWR_SOC_BITS    (7)
#define UPWR_VMINOR_BITS (4)
#define UPWR_VFIXES_BITS (4)
#define UPWR_VMAJOR_BITS \
           (32-UPWR_HEADER_BITS-UPWR_SOC_BITS-UPWR_VMINOR_BITS-UPWR_VFIXES_BITS)

typedef struct {
	uint32_t soc_id;
	uint32_t vmajor;
	uint32_t vminor;
	uint32_t vfixes;
} upwr_code_vers_t;

/* message sent by firmware initialization, received by upwr_init */

typedef union {
	struct upwr_resp_hdr hdr;
	struct {
		uint32_t rsv:UPWR_RESP_HDR_BITS;
		uint32_t soc:UPWR_SOC_BITS;        /* SoC identification */
		uint32_t vmajor:UPWR_VMAJOR_BITS;  /* firmware major version */
		uint32_t vminor:UPWR_VMINOR_BITS;  /* firmware minor version */
		uint32_t vfixes:UPWR_VFIXES_BITS;  /* firmware fixes version */
	} args;
} upwr_init_msg;

/* message sent by firmware when the core platform is powered up */

typedef upwr_resp_msg upwr_power_up_msg;

/* message sent by firmware when the core reset is released for boot */

typedef upwr_resp_msg upwr_boot_up_msg;

/* message sent by firmware when ready for service requests */

#define UPWR_RAM_VMINOR_BITS (7)
#define UPWR_RAM_VFIXES_BITS (6)
#define UPWR_RAM_VMAJOR_BITS (32-UPWR_HEADER_BITS \
                                -UPWR_RAM_VFIXES_BITS-UPWR_RAM_VMINOR_BITS)

typedef union {
	struct upwr_resp_hdr hdr;
	struct {
		uint32_t rsv:UPWR_RESP_HDR_BITS;
		uint32_t vmajor:UPWR_RAM_VMAJOR_BITS; /* RAM fw major version */
		uint32_t vminor:UPWR_RAM_VMINOR_BITS; /* RAM fw minor version */
		uint32_t vfixes:UPWR_RAM_VFIXES_BITS; /* RAM fw fixes version */
	} args;
} upwr_ready_msg;

/* message sent by firmware when shutdown finishes */

typedef upwr_resp_msg upwr_shutdown_msg;

typedef union {
	struct upwr_resp_hdr hdr;
	upwr_init_msg        init;
	upwr_power_up_msg    pwrup;
	upwr_boot_up_msg     booted;
	upwr_ready_msg       ready;
} upwr_startup_up_msg;

/* message sent by firmware for uPower config setting */

typedef upwr_resp_msg upwr_config_resp_msg;

/* message sent by firmware for uPower alarm */

typedef upwr_resp_msg upwr_alarm_resp_msg;

/* *************************************************************************
 * Power Management - upstream
 ***************************************************************************/

typedef upwr_resp_msg upwr_param_resp_msg;

#ifdef  __cplusplus
#ifndef UPWR_NAMESPACE /* extern "C" 'cancels' the effect of namespace */
} /* extern "C" */
#endif
#endif

#endif /* #ifndef _UPWR_DEFS_H */
