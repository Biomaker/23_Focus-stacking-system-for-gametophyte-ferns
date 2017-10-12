
<img src="images/banner.jpg" alt="image"/>


<img src="images/Jennifer-Deegan.jpg" alt="image"/><br>
Jennifer Deegan<br>

<img src="images/Tim Deegan.jpg" alt="image"/><br>
Tim Deegan<br>

<img src="images/Richard Mortier.jpg" alt="image"/><br>
Richard Mortier<br>

<img src="images/matthew_couchman.jpg" alt="image"/><br>
Matthew Couchman<br>

## Synopsis

The aim of this project is to home-build a microscope capable of photographing gametophyte ferns. The style of photography aims to produce attractive images of the sort that might normally be seen on the front of Gardeners' World Magazine, or similar. 

The technique to be used is called focus stacking and Jennifer Deegan has already worked extensively on developing a system. She has taken a fairly good photograph of a gametophyte fern, using a <a href="Background.md">set up that relies on a modified flatbed scanner</a> (image below). For a full understanding of focus stacking please refer to the <a href="Background.md">flatbed scanner introduction page</a>. The aim of this current project is to significantly improve on that first image. 

<img src="images/stackimagetinyweb.jpg" alt="image"/>

This project is a collaboration between many people. The principles of the design came from the forum members at  http://www.photomacrography.net/. The design is particularly based on the Bratcam, by Chris Slaybaugh. The focus block was provided as a gift by one of the forum members (Doc.Al). Some of the electronics and programming, and some of the fitting together were carried out by Tim Deegan. He also helped with the principles of the design. Jennifer Deegan did everything else.

Here are some of the fern photos that we managed to take with the finished setup:

<img src="images/20171008fernstack.jpg" alt="image"/>

<img src="images/20171009fernstack.jpg" alt="image"/>



## Hardware

There is a lot of complex hardware involved in this project, so a structured introduction is given on this page, and each section references another page, on which details of that part are given. 

The following is an image of the full photographic setup including the optics, electronics and laptop:

<img src="images/IMG_6882.JPG" alt="image"/>

This is the setup including just the optics and electronics:

<img src="images/IMG_6878.JPG" alt="image"/>

This picture shows the optics:

<img src="images/IMG_6876.JPG" alt="image"/>




### Rail Hardware

The <a href="rail.md"> hardware for the rail</a> is one of the most critical parts, as this gives very fine control over the movement of the camera, and underpins the quality of the slices from which the stack is derived.  

### Hardware for the optics. 

The quality of the <a href="//optics.md"> optics</a> is critical, as this determines the quality of the slices from which the final stacked image is derived. 

There is also an investigation of the <a href="//DepthOfField.md">depth of field</a> of the optics, using a stage micrometer. 

### Hardware for the lighting. 

Effective <a href="/lighting.md">lighting</a> of gametophyte ferns for macrophotography is very tricky. These subjects are translucent and tend to produce specular highlights when the cells reflect the light of a camera flash, or create diffuse white lighting across the whole image. We have attempted to mitigate these issues using the techniques described. 

### Hardware to minimise vibration

<a href="vibration.md">Vibration</a> is an important factor in photography at this tiny scale, so we used specific methods and hardware to control it.

### Other hardware

Fern specimens are mounted on a piece of blutac on top of a paint pot. The lens of the camera needs to be slightly propped up to be horizontal and this is done by putting a pencil eraser under it. 

## Software

There is a lot of software involved in this project. Some was bought, and some was written by Jennifer and Tim Deegan. 

### In-house software

Software was written in-house to drive the rail. We provide instructions on how to drive the rail system using either an <a href="ArduinoMethod.md">Arduino</a> or a <a href="RaspberryPiMethod.md">Raspberry Pi</a>. Please see one or other of these pages for the software documentation depending on which hardware you are using. 

### Bought software

The following pieces of commercial software were used:

Helicon focus for stacking the images<br>
EOS Remote for focussing the camera and figuring out the camara settings. <br>
Adobe photoshop. 

## Growing ferns

Growing the photographic specimens is one of the trickiest parts of this project. The <a href="GrowingFerns.md"> protocol</a> that I am using is described. 

## Installation, Maintenance and Testing Guide

a <a href="Test.md"> guide to testing</a> is provided. 

## What didn't work

I tried some other options that <a href="WhatDidntWork.md">didn't work</a>. I describe them here to avoid others duplicating effort. 

## License

If anybody would like to copy the hardware and software that we have designed here, they are welcome to do it, but they must provide full attribution, and an appropriate fee in the case of commercial use. The design has been accepted in principle for publication in the Pteridologist Magazine 2018, so attribution should cite "Deegan, J. and Deegan, T. (2018), The Pteridologist Magazine". 

The copyright of any photographs produced using this equipment is owned by Jennifer Deegan. Anyone who wishes to use the photographs should approach her directly through the <a href="http://chlorophyllosophyimages.blogspot.co.uk/2016/12/the-chlorophyllosophy-image-library.html"> Chlorophyllosophy Image Library</a> or through the <a href="https://www.plantsci.cam.ac.uk/directory/deegan-jennifer">University of Cambridge</a>. This copyright also applies to the photographs of the system used on this website. 


