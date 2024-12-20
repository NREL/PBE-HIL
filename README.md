# PBE-HIL
**(Powering the Blue Economy Hardware-in-the-Loop models)**

PBE-HIL is a repository of Power Hardware-in-the-loop models developed for typical Powering the Blue Economy market loads and power requirements. The HIL models were developed to be as generic and functional as possible, meaning that the user can easily configure these models to represent their unique PBE design. These PBE load and power requirement HIL models can then be used to inform marine energy converter (MEC) and power electronics design, as well as be used in laboratory testing using HIL equipment, leading to improved understanding of MEC performance and lower risk prior to open-water MEC deployment.

The current PBE HIL models that are available are:
* Ocean Observation
* Autonomous Underwater Vehicle charging
* Marine energy integration with microgrids (Future)

## Documentation

PBE-HIL documentation includes introductory information to the Power Hardware-in-the-Loop simulation software and how to use these models.
See the [PBE-HIL](https://github.nrel.gov/clabusch/PBE-HIL-internal/wiki) documentation for more information.

## Software

The PBE applications in this repository are modeled using the Typhoon HIL software. This software uses a schematic editor to build the hardware simulation model and a Supervisory Control and Data Acquisition (SCADA) panel to simulate the model with real-time user inputs. Both the schematic editor and the SCADA panel can accept user inputs from a Python API. Therefore, Python scripts are developed that make it possible for the user to configure their HIL model and assign values to power electronic components or passive circuit elements. This is illustrated in the schematic below. The Python scripts also allow the user to specify generic component values that were obtained from a load and power requirement survey, as well as the functionality of specifying custom component values.

<p align="center">
<img src="https://github.nrel.gov/clabusch/PBE-HIL-internal/blob/main/wiki_images/Typhoon_Python_API.png" width="500" height="250" >
</p>
<p align="center">
<em>Figure 1: Schematic illustrating the functionality of the developed PBE load models using the Typhoon HIL software and Python API.</em>
</p>
<br><br>
The following links are provided for quick access to Typhooh HIL software and Python documentation:
<br><br>

&emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; [<img src="https://github.nrel.gov/clabusch/PBE-HIL-internal/blob/main/wiki_images/python-logo-master-v3-TM.png" width="280" height="100" />](https://www.python.org/) &emsp; &emsp; &emsp; [<img src="https://github.nrel.gov/clabusch/PBE-HIL-internal/blob/main/wiki_images/Typhoon-HIL.png" width="130" height="100" />](https://www.typhoon-hil.com/)

<p align="center">
  
&emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; _Figure 2: Software packages used in this GitHub repository._
</p>

### Don't have Typhoon HIL?

Under the respective folders for _Ocean Ovservation_ and _AUV charging_ there are two folders, one named "_Model Schematics_" and the other "_Typhoon Specific Files_".

* "_Model Schematics_" - Contains schematics that can be copied to a different HIL software or used when designing/building a new model.
* "_Typhoon Specific Files_" - Contains the Typhoon HIL files used for the OOB and AUV examples.

## PBE-HIL contributors

PBE-HIL is developed at the National Renewable Energy Laboratory (NREL), by members of the _Water Power Technology Validation_ group.

Current members of the core development team include:

* Hannes Labuschagne
* Rebecca Fao
* Alec Schnabel (Future contributor)


## Copyright and License

PBE-HIL is copyright through the National Renewable Energy Laboratory. 
## Funding

The development of PBE-HIL is funded by the U.S. Department of Energy’s Water Power Technologies Office. 

The [National Renewable Energy Laboratory](https://www.nrel.gov/) (NREL) is a national laboratory of the U.S. Department of Energy, Office of Energy Efficiency and Renewable Energy, operated by the Alliance for Sustainable Energy, LLC. under contract No. DE-AC36-08GO28308.

## Acknowledgements

The authors would like to thank Namrata Rajput, and acknowledge her contributions to the
project. 
