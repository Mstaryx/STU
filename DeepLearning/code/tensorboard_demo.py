from torch.utils.tensorboard import SummaryWriter
from PIL import Image

writer = SummaryWriter("logs")
for i in range(100):
    writer.add_scalar("y=4x",4*i,i)
