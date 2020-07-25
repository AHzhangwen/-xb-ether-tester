/* 
 * �����Ϊ��ѡ���Դ�����
 * ������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */
#include <windows.h>
#include "res.h"
#include "global_info.h"
#include "gui.h"

HINSTANCE g_hInstance;
TCHAR     szAppName[] = TEXT ("Xiaobing ethernet tester") ;
int init_over;


void run_env_init()
{
    char exe_file_path[MAX_FILE_PATH_LEN];
    char *pchar;
    init_gui_info();
    CreateDirectory("C:\\WINDOWS\\temp", NULL);
    GetModuleFileName(NULL,  exe_file_path,  sizeof(exe_file_path));
    pchar=strrchr(exe_file_path, '\\');
    *pchar=0;
    SetCurrentDirectory(exe_file_path);

}

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
             PSTR szCmdLine, int iCmdShow)
{

    MSG     msg ;
    HACCEL  hAccel ;

    g_hInstance = hInstance;

    reg_sys_win_classes();
    register_frame();
    register_left_win();
    register_right_win();
    register_bottom_win();
    register_splt_wins();
    register_hex_edit_win();
    //register_flat_tab_win();
    register_stats_win();
    register_tip_win();
    register_ver_update_win();

    run_env_init();
    
    create_windows(iCmdShow);

 	hAccel = LoadAccelerators (hInstance, TEXT("MY_ACCELER")) ;
    init_over=1;
 	while (GetMessage (&msg, NULL, 0, 0))
 	{
  		if (!TranslateAccelerator (hwnd_frame, hAccel, &msg))
		{
			TranslateMessage (&msg) ;
            if (msg.message==WM_KEYDOWN && VK_RETURN==msg.wParam && msg.hwnd==hwnd_dynamic_edit)
            {
                msg.hwnd = hwnd_stream;
            }
			DispatchMessage (&msg) ;
  		}
 	}

    return msg.wParam ;
}


