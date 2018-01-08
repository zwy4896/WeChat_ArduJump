# WeChat_ArduJump
微信“跳一跳”游戏物理辅助 by zwy4896

感谢wangshub大神对我的启发，辅助的python核心代码以及其他代码，请访问https://github.com/wangshub/wechat_jump_game ，我这里仅做Arduino端代码，wangshub大神的python代码我仅做了极少的修改，就是调用了pyserial模块。目前python代码尚未调试完毕。

原理：

通过ADB截取跳一跳游戏界面的图片，经过计算机处理，将小人和方块中心的距离算出来，通过转换公式，将距离转换为触屏时间，通过串口，将时间数据发送到Arduino上，进而
控制舵机旋转。可以实现自主物理外挂（想想都很兴奋呢）。

硬件清单：

  1. Arduino
  2. 舵机
  3. 7.4V电池(Optional)
  4. 电容笔 or 自制
  
软件及驱动：

   参考https://github.com/wangshub/wechat_jump_game 里列出的需要准备的软件及驱动
