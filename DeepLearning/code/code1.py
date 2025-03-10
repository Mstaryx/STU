from conda.exports import root_dir
from torch.utils.data import Dataset
from PIL import Image
import os

class MyData(Dataset):
    def __init__(self, root_dir,label_dir):
        self.root_dir = root_dir
        self.label_dir = label_dir
        self.path = os.path.join(self.root_dir,self.label_dir)#拼接数据集文件path
        self.img_list=os.listdir(self.path)#获取数据集array
    def __getitem__(self,index):
        img_name=self.img_list[index]
        img_item_path=os.path.join(self.path,img_name)#获取图片path
        img=Image.open(img_item_path)
        label=self.label_dir
        return img,label
    def __len__(self):
        return len(os.listdir(self.img_list))

root_dir='../Dataset_1\\train'
label_dir='ants'
ants_data=MyData(root_dir,label_dir)
img,label=ants_data[0]
img.show()
