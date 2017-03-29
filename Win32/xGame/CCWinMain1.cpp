#include<glut.h>  
  
void myDisplay(void)  
{  
    glClear(GL_COLOR_BUFFER_BIT);     //清除颜色  
    glRectf(-0.5f,-0.5f,0.5f,0.5f);    //画一个矩形  
    glFlush();   //让前面的命令立即执行而不是在缓冲区，与fflush(stdout)作用类似  
}  
  
int main(int argc,char* argv[])  
{  
    glutInit(&argc,argv);    //初始化glut,必须调用，复制黏贴这句话即可  
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //设置显示方式，RGB、单缓冲。当然还有GLUT_INDEX索引颜色 GLUT_DOUBLE双缓冲 
    glutInitWindowPosition(100,100);   //位置  
    glutInitWindowSize(400,400);//窗口大小  
    glutCreateWindow("第一个OpenGL程序");  //创建窗口，设置标题  
    glutDisplayFunc(&myDisplay);  // 当绘制窗口时调用myDisplay，像Cocos2d-x刷帧Draw中的操作  
	glutIdleFunc(&myDisplay);
    glutMainLoop();  //消息循环  
    return 0;  
} 