SeatEasy_Node
=============

这是我们项目的部分源程序。

项目开发环境：

    操作系统：		Windows XP SP3

    IDE：		IAR Embedded Workbench for 8051 version=7.60A

    Zigbee协议栈：	ZStack-CC2530-2.3.0-1.4.0

    硬件平台：		网蜂（WeBee）ZigBee开发套件（核心板、底板、仿真器）

参考资料：

    《Zigbee实战演练》 WeBee

使用方法：

    1.对照《Zigbee实战演练》安装IAR IDE、ZStack、开发板驱动，保证所有东西工作正常

    2.备份 'ZStack安装路径'\Z-stack\Projects\zstack\Samples 目录下的 SampleApp 文件夹

    3.将IR.c、IR.h、OSAL_SampleApp.c、SampleAppHw.h、SampleApp.h、SampleApp.c这些文件放入 'ZStack安装路径'\Z-stack\Projects\zstack\Samples\SampleApp\Source 目录下

    4.将 SampleAppHw.c 这个文件放入 'ZStack安装路径'\Z-stack\Projects\zstack\Samples\SampleApp\CC2530DB\Source 目录下

    5.用IAR打开 'ZStack安装路径'\Z-stack\Projects\zstack\Samples\SampleApp\CC2530DB\SampleApp.eww 这个WorkSpace

    6.添加上述所有文件到项目的 App 目录中

    7.编译、下载到开发板中，调试运行
