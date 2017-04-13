![image](https://github.com/ThisisGame/Lives2D/blob/master/Docs/Logo.png)


Lives2D is a simple 2D gameengine,it is degined to learn opengles.

you can use to make game too.


## V1_Only_ImageDraw_Windows

V1_Only_ImageDraw_Windows is simplest version ,only draw images. very easy to learn.



## Run

First you need vs2015 community,open sln file in  Lives2D\Win32\Lives2D\Lives2D.sln and press F5 run it.

![image](https://github.com/ThisisGame/Lives2D/blob/V1_Only_ImageDraw_Windows/Docs/drawimage.png)

## Draw

the only thing you can do is create a image and draw it.

in the sample,i create a Image in Lives2D.cpp.

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
void Lives2D::Draw()
{
	//绘制一个图片
	mImage->Draw();
}
```

