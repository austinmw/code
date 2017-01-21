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
    work_m_00043783120188966251_2857299581_init();
    work_m_17607930559397885458_1514806922_init();
    work_m_13100572551147950247_3179704038_init();
    work_m_08013870773365304131_1638322650_init();
    work_m_14103377745844267320_0612177658_init();
    work_m_09510542955919353355_1749120898_init();
    work_m_00232367842581890089_1384337587_init();
    work_m_16541823861846354283_2073120511_init();


    xsi_register_tops("work_m_00232367842581890089_1384337587");
    xsi_register_tops("work_m_16541823861846354283_2073120511");


    return xsi_run_simulation(argc, argv);

}
