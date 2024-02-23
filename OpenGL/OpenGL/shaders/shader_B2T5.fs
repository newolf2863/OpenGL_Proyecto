#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;
in vec3 ourPosition;

// texture samplers
uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float visible;

void main()
{
    if (ourPosition.y < 0.00) {
        // Si la posición y es menor que 0.00, utiliza la textura 1
        FragColor = mix(texture(texture1, TexCoord), vec4(ourColor, 1.0), visible);
    } else {
        // Si la posición x es mayor o igual a 0.00, utiliza la textura 2
        //FragColor = mix(texture(texture2, TexCoord), vec4(ourColor, 1.0), 1.0f);
        FragColor = mix(texture(texture2, TexCoord), vec4(ourColor, 1.0), visible);
    }
}
