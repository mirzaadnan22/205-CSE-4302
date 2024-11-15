#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

enum THERMOSTAT_MODE {
  THERMOSTAT_MODE_COOLING,
  THERMOSTAT_MODE_HEATING,
  THERMOSTAT_MODE_FAN
};

struct TemperatureRange {
  double min;
  double max;
};

string getModeString(THERMOSTAT_MODE mode) {
  if (mode == THERMOSTAT_MODE_COOLING) {
    return "Cooling";
  }
  else if (mode == THERMOSTAT_MODE_HEATING) {
    return "Heating";
  }
  else if (mode == THERMOSTAT_MODE_FAN) {
    return "Fan-only";
  }
  return "Unknown";
}

class SmartDevice {
protected:
  int deviceID;
  string brandName;
  double powerRating;

public:
  SmartDevice(int dID, string _brand, double power) {
    deviceID = dID;
    brandName = _brand;
    powerRating = power;
  }

  virtual void diagnose() = 0;

  double getPowerRating() {
    return powerRating;
  }
};

class ThermostatDevice : virtual public SmartDevice {
protected:
  TemperatureRange tempRange;
  THERMOSTAT_MODE mode;

public:
  ThermostatDevice(int _dID, string _brand, double _power, double _max, double _min, THERMOSTAT_MODE _mode)
    : SmartDevice(_dID, _brand, _power) {
    tempRange.max = _max;
    tempRange.min = _min;
    mode = _mode;
  }

  virtual double calculatePowerConsumption(double hours) {
    return powerRating * (hours * 60 * 60);
  }

  void diagnose() override {
    cout << "Device ID: " << deviceID << "\n";
    cout << "Power Rating: " << powerRating << " watts\n";
    cout << "Temperature Range: " << tempRange.max << " - " << tempRange.min << "\n";
    cout << "Mode: " << getModeString(mode) << "\n";
  }
};

class SecurityCameraDevice : virtual public SmartDevice {
protected:
  string resolution;
  double recordingHours;

public:
  SecurityCameraDevice(int _dID, string _brand, double _power, string _res, double _recHrs)
    : SmartDevice(_dID, _brand, _power) {
    resolution = _res;
    recordingHours = _recHrs;
  }

  virtual double calculateDataUsage(double days) {
    return powerRating * (days * recordingHours * 60 * 60);
  }

  void diagnose() override {
    cout << "Security Camera\n";
    cout << "Device ID: " << deviceID << "\n";
    cout << "Power Rating: " << powerRating << " watts\n";
    cout << "Resolution: " << resolution << "\n";
    cout << "Recording Hours: " << recordingHours << " hours\n";
  }
};

class SmartThermostat : public ThermostatDevice {
protected:
  bool remoteControlEnabled;

public:
  SmartThermostat(int _dID, string _brand, double _power, double _max, double _min, THERMOSTAT_MODE _mode, bool rmtCtrl)
    : ThermostatDevice(_dID, _brand, _power, _max, _min, _mode), SmartDevice(_dID, _brand, _power) {
    remoteControlEnabled = rmtCtrl;
  }

  void diagnose() override {
    cout << "Smart Thermostat\n";
    ThermostatDevice::diagnose();
    cout << "Remote Controlled: " << (remoteControlEnabled ? "Yes\n" : "No\n");
  }
};

class HybridThermostat : public ThermostatDevice, public SecurityCameraDevice {
private:
  float energySavingEfficiency;

public:
  HybridThermostat(int _dID, string _brand, double _power,
    double _maxTemp, double _minTemp, THERMOSTAT_MODE _mode,
    string _resolution, double _recordingHours,
    float _efficiency)
    : SmartDevice(_dID, _brand, _power),
    ThermostatDevice(_dID, _brand, _power, _maxTemp, _minTemp, _mode),
    SecurityCameraDevice(_dID, _brand, _power, _resolution, _recordingHours),
    energySavingEfficiency(_efficiency) {
  }

  double calculateDataUsage(double days) {
    double thermostatDataUsage = powerRating * days * 10; // Hypothetical data usage
    double cameraDataUsage = recordingHours * days * 50;
    return thermostatDataUsage + cameraDataUsage;
  }

  double calculatePowerConsumption(double hours) override {
    double thermostatConsumption = ThermostatDevice::calculatePowerConsumption(hours);
    double cameraConsumption = SecurityCameraDevice::calculateDataUsage(1) / 24; // Hypothetical calculation
    double totalConsumption = thermostatConsumption + cameraConsumption;

    totalConsumption *= (1 - energySavingEfficiency / 100.0);
    return totalConsumption;
  }

  void diagnose() override {
    cout << "Hybrid Thermostat\n";
    ThermostatDevice::diagnose();
    cout << "Resolution: " << resolution << "\n";
    cout << "Recording Hours: " << recordingHours << " hours\n";
    cout << "Energy Saving Efficiency: " << energySavingEfficiency << "%\n";
  }
};

void sort_devices_by_power(SmartDevice** devices, int n) {
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (devices[i]->getPowerRating() < devices[j]->getPowerRating()) {
        swap(devices[i], devices[j]);
      }
    }
  }
}

int main() {
  SmartDevice* devices[4];
  devices[0] = new ThermostatDevice(1, "Philips", 200.0, 30.0, 15.0, THERMOSTAT_MODE_COOLING);
  devices[1] = new SecurityCameraDevice(2, "Sony", 150.0, "1080p", 8.0);
  devices[2] = new HybridThermostat(3, "Samsung", 300.0, 32.0, 20.0, THERMOSTAT_MODE_FAN, "4K", 24.0, 20.0);
  devices[3] = new SmartThermostat(4, "Apple", 600.0, 40.0, 15.0, THERMOSTAT_MODE_HEATING, true);

  sort_devices_by_power(devices, 4);

  cout << "Devices sorted by power rating:\n";
  for (int i = 0; i < 4; i++) {
    devices[i]->diagnose();
    cout << "\n\n";
  }

  for (int i = 0; i < 4; i++) {
    delete devices[i];
  }

  return 0;
}
