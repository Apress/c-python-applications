from PIL import Image, ImageDraw, ImageFont
#Open image using Image module
im = Image.open("5Rome.jpg") #photograph of Rome

myFont = ImageFont.truetype(r'C:\Users\System-Pc\Desktop\arial.ttf', 80)


d1 = ImageDraw.Draw(im)

d1.text((28, 36), "Rome 2016", font=myFont, fill=(255, 0, 0))

#Show final Image
im.show()
