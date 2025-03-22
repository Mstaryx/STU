from torch.utils.tensorboard import SummaryWriter
from PIL import Image
import numpy as np
writer = SummaryWriter("logs")
img_path='../Dataset_1/train/ants/5650366_e22b7e1065.jpg'
img_PIL = Image.open(img_path)
# print(img_PIL)
img_array = np.array(img_PIL)
# print(img_array.shape)
writer.add_image('testPic',img_array,2,dataformats='HWC')

# for i in range(100):
#     writer.add_scalar("y=4x",4*i,i)
writer.close()