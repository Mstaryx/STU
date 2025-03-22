import torch
import torchvision
from torch import nn
from torch.utils.data import DataLoader
from torch.utils.tensorboard import SummaryWriter
from torchvision.transforms import transforms

#最大池化的练手简单示例
#导入并打包数据集
dataset=torchvision.datasets.CIFAR10("../Dataset_2",train=False,download=True,transform=transforms.Compose([transforms.ToTensor()]))
data_loader=DataLoader(dataset,64,shuffle=False,num_workers=0,drop_last=True)
#定义卷积操作
class MyPool(nn.Module):
    def __init__(self):
        super(MyPool,self).__init__()
        self.maxpool = nn.MaxPool2d(kernel_size=3,ceil_mode=True)
    def forward(self,x):
        x = self.maxpool(x)
        return x
#开始运行
writer=SummaryWriter(log_dir='../logs')
my_pool=MyPool()
steps=0
for data in data_loader:
    imgs,targets=data
    # print(imgs.shape)
    outputs=my_pool(imgs)
    writer.add_images('input_pool',imgs,steps)
    writer.add_images('output_pool',outputs,steps)
    steps+=1
writer.close()