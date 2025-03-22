from os import close

from torch.utils.tensorboard import SummaryWriter
from torchvision import transforms
from PIL import Image

img_path='../Dataset_1/train/ants/0013035.jpg'
img=Image.open(img_path)
writer=SummaryWriter('logs')
#ToTensor
trans_tensor=transforms.ToTensor()
img_tensor=trans_tensor(img)
#Normalize
trans_norm=transforms.Normalize(mean=[0.5, 0.5, 0.5], std=[0.5, 0.5, 0.5])
img_norm=trans_norm(img_tensor)
#Compose
trans_resize=transforms.Resize((400,400))
trans_comp=transforms.Compose([trans_tensor,trans_resize])
img_comp=trans_comp(img)
print(img_comp)
writer.add_image('tensor',img_comp,2)
writer.add_image('tensor',img_tensor,0)
writer.add_image('tensor',img_norm,1)
writer.close()