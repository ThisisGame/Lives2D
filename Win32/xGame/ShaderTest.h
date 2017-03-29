static const char g_VertexShaderTest[]=
	"varying vec3 normal, lightDir; \n"
"void main()\n"
"{	\n"
"	lightDir = normalize(vec3(gl_LightSource[0].position));\n"
"	normal = normalize(gl_NormalMatrix * gl_Normal);		\n"
"	gl_Position = ftransform();\n"
"}\n";

static const char g_FragShaderTest[]=
	"varying vec3 normal, lightDir;\n"
"void main()\n"
"{\n"
"	float intensity;\n"
"	vec3 n;\n"
"	vec4 color;\n"
"	n = normalize(normal);\n"
"	intensity = max(dot(lightDir,n),0.0); \n"
"	if (intensity > 0.98)\n"
"		color = vec4(0.8,0.8,0.8,1.0);\n"
"	else if (intensity > 0.5)\n"
"		color = vec4(0.4,0.4,0.8,1.0);	\n"
"	else if (intensity > 0.25)\n"
"		color = vec4(0.2,0.2,0.4,1.0);\n"
"	else\n"
"		color = vec4(0.1,0.1,0.1,1.0);	\n"	
"	gl_FragColor = color;\n"
"}\n";