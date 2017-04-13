![image](https://github.com/ThisisGame/Game2D/blob/master/Docs/Logo.png)


Game2D is a simple 2D gameengine,it is degined to learn opengles.

you can use to make game too.


## V1_Only_ImageDraw_Windows

V1_Only_ImageDraw_Windows is simplest version ,only draw images. very easy to learn.



## Run

First you need vs2015 community,open sln file in  Game2D\Win32\Game2D\Game2D.sln and press F5 run it.

![image](https://github.com/ThisisGame/Game2D/blob/V1_Only_ImageDraw_Windows/Docs/drawimage.png)

## Draw

the only thing you can do is create a image and draw it.

in the sample,i create a Image in Game2D.cpp.

import Image head file.
```
#include"Image\Image.h"
```

then 

```
Image* mImage;
```

then Init with png path

```
mImage = new Image();
mImage->Init("../../Resources/images/logo.png");
```

then draw it

```
void Game2D::Draw()
{
	//绘制一个图片
	mImage->Draw();
}
```

