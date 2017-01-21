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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_13702768314521208559_1367678787_init();
    work_m_17607930559397885458_1514806922_init();
    work_m_13100572551147950247_3179704038_init();
    work_m_17394698963096725896_2475965825_init();
    work_m_16664448635384714869_0768308253_init();
    work_m_16541823861846354283_2073120511_init();


    xsi_register_tops("work_m_16664448635384714869_0768308253");
    xsi_register_tops("work_m_16541823861846354283_2073120511");


    return xsi_run_simulation(argc, argv);

}
