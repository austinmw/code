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
    work_m_14291455753022248745_0722118379_init();
    work_m_05584263903964236627_1010895172_init();
    work_m_12223667007573120156_3225230824_init();
    work_m_12926411539576915697_2647877144_init();
    work_m_04738387122580452307_0843939667_init();
    work_m_05711373338368783897_3638393797_init();
    work_m_16541823861846354283_2073120511_init();


    xsi_register_tops("work_m_05711373338368783897_3638393797");
    xsi_register_tops("work_m_16541823861846354283_2073120511");


    return xsi_run_simulation(argc, argv);

}
