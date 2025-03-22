import torch
from sympy.codegen.fnodes import reshape
from torch import nn
import torchvision
from torch.utils.tensorboard import SummaryWriter
from torchvision import transforms
from torch.utils.data import DataLoader

dataset=torchvision.datasets.CIFAR10("../Dataset_2",train=False,download=True,transform=transforms.Compose([transforms.ToTensor()]))
data_loader=DataLoader(dataset,64,shuffle=False,num_workers=0,drop_last=True)
class Mymodule(nn.Module):
    def __init__(self):
        super(Mymodule,self).__init__()
        self.conv1=nn.Conv2d(in_channels=3,out_channels=6,kernel_size=3,stride=1,padding=0)
    def forward(self,x):
        x=self.conv1(x)
        return x
writer=SummaryWriter('../logs')
my_model=Mymodule()
steps=0
for data in data_loader:
     imgs,targets=data
     outputs=my_model(imgs)
     #-1时，自动计算合适的batch
     outputs=torch.reshape(outputs,(-1,3,30,30))
     writer.add_images('input',imgs,steps)
     writer.add_images('output',outputs,steps)
     steps+=1
writer.close()
