#include "Stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "cat_frames.h" 

// 修改后的显示函数：接收一个数组作为参数
void OLED_ShowBitmap(const unsigned char* bitmap)
{
    uint8_t page, col;
    for (page = 0; page < 8; page++)
    {
        OLED_SetCursor(page, 0);
        for (col = 0; col < 128; col++)
        {
            // 计算索引并显示
            uint16_t index = page * 128 + col;
            OLED_WriteData(bitmap[index]);
        }
    }
}

int main(void)
{
    OLED_Init(); // 初始化屏幕

    // 把所有帧的数组指针存到一个列表里
    const unsigned char* cat_frames[] = {
        cat_frame_1, cat_frame_2, cat_frame_3, cat_frame_4,
        cat_frame_5, cat_frame_6, cat_frame_7, cat_frame_8,
        cat_frame_9, cat_frame_10, cat_frame_11, cat_frame_12,
        cat_frame_13, cat_frame_14, cat_frame_15,cat_frame_16,
			cat_frame_17,cat_frame_18,cat_frame_19,cat_frame_20,cat_frame_21,
			cat_frame_22
    };

    // 计算总帧数
    int total_frames = sizeof(cat_frames) / sizeof(cat_frames[0]);

    while (1)
    {
        for (int i = 0; i < total_frames; i++)
        {
            // 每次先清屏（动画流畅度优先，如果闪可以去掉这行）
            OLED_Clear();
            
            // 显示当前帧
            OLED_ShowBitmap(cat_frames[i]);
            
            // 延时：控制播放速度，单位毫秒
            Delay_ms(80); 
        }
			OLED_ShowBitmap(bb);
			//Delay_ms(80); 
    }
}
