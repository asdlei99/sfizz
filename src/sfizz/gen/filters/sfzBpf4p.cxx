/* ------------------------------------------------------------
author: "Jean Pierre Cimalando"
license: "BSD-2-Clause"
name: "sfz_filters"
Code generated with Faust 2.20.2 (https://faust.grame.fr)
Compilation options: -lang cpp -inpl -double -ftz 0
------------------------------------------------------------ */

#ifndef  __faustBpf4p_H__
#define  __faustBpf4p_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <algorithm>
#include <cmath>
#include <math.h>


#ifndef FAUSTCLASS
#define FAUSTCLASS faustBpf4p
#endif

#ifdef __APPLE__
#define exp10f __exp10f
#define exp10 __exp10
#endif

class faustBpf4p : public sfzFilterDsp {

 public:

	int fSampleRate;
	double fConst0;
	double fConst1;
	double fConst2;
	FAUSTFLOAT fCutoff;
	FAUSTFLOAT fQ;
	double fRec2[2];
	double fRec5[2];
	double fVec0[2];
	double fRec6[2];
	double fVec1[2];
	double fRec7[2];
	double fVec2[2];
	double fRec8[2];
	double fRec4[2];
	double fRec3[2];
	double fVec3[2];
	double fVec4[2];
	double fVec5[2];
	double fRec1[2];
	double fRec0[2];

 public:

	void metadata(Meta* m) {
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch ((channel)) {
			case 0: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch ((channel)) {
			case 0: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}

	static void classInit(int sample_rate) {
	}

	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSampleRate)));
		fConst1 = std::exp((0.0 - (1000.0 / fConst0)));
		fConst2 = (6.2831853071795862 / fConst0);
	}

	virtual void instanceResetUserInterface() {
		fCutoff = FAUSTFLOAT(440.0);
		fQ = FAUSTFLOAT(0.0);
	}

	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec2[l0] = 0.0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec5[l1] = 0.0;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fVec0[l2] = 0.0;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec6[l3] = 0.0;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fVec1[l4] = 0.0;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec7[l5] = 0.0;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fVec2[l6] = 0.0;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec8[l7] = 0.0;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec4[l8] = 0.0;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec3[l9] = 0.0;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fVec3[l10] = 0.0;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fVec4[l11] = 0.0;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fVec5[l12] = 0.0;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec1[l13] = 0.0;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec0[l14] = 0.0;
		}
	}

	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}

	virtual faustBpf4p* clone() {
		return new faustBpf4p();
	}

	virtual int getSampleRate() {
		return fSampleRate;
	}

	virtual void buildUserInterface(UI* ui_interface) {
	}

	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		double fSlow0 = (fSmoothEnable ? fConst1 : 0.0);
		double fSlow1 = (fConst2 * std::max<double>(0.0, double(fCutoff)));
		double fSlow2 = std::sin(fSlow1);
		double fSlow3 = std::max<double>(0.001, std::pow(10.0, (0.050000000000000003 * double(fQ))));
		double fSlow4 = (0.5 * (fSlow2 / fSlow3));
		double fSlow5 = (fSlow4 + 1.0);
		double fSlow6 = (0.5 * (fSlow2 / (fSlow3 * fSlow5)));
		double fSlow7 = (1.0 - fSlow0);
		double fSlow8 = ((0.0 - fSlow6) * fSlow7);
		double fSlow9 = (fSlow6 * fSlow7);
		double fSlow10 = (((1.0 - fSlow4) / fSlow5) * fSlow7);
		double fSlow11 = (((0.0 - (2.0 * std::cos(fSlow1))) / fSlow5) * fSlow7);
		for (int i = 0; (i < count); i = (i + 1)) {
			double fTemp0 = double(input0[i]);
			fRec2[0] = ((fSlow0 * fRec2[1]) + fSlow8);
			fRec5[0] = (fSlow0 * fRec5[1]);
			fVec0[0] = (fTemp0 * fRec5[0]);
			fRec6[0] = ((fSlow0 * fRec6[1]) + fSlow9);
			fVec1[0] = (fTemp0 * fRec2[0]);
			fRec7[0] = ((fSlow0 * fRec7[1]) + fSlow10);
			fVec2[0] = (fVec1[1] - (fRec7[0] * fRec3[1]));
			fRec8[0] = ((fSlow0 * fRec8[1]) + fSlow11);
			fRec4[0] = ((fVec0[1] + ((fTemp0 * fRec6[0]) + fVec2[1])) - (fRec8[0] * fRec4[1]));
			fRec3[0] = fRec4[0];
			fVec3[0] = (fRec2[0] * fRec3[0]);
			fVec4[0] = (fVec3[1] - (fRec7[0] * fRec0[1]));
			fVec5[0] = (fRec5[0] * fRec3[0]);
			fRec1[0] = (((fVec4[1] + fVec5[1]) + (fRec6[0] * fRec3[0])) - (fRec8[0] * fRec1[1]));
			fRec0[0] = fRec1[0];
			output0[i] = FAUSTFLOAT(fRec0[0]);
			fRec2[1] = fRec2[0];
			fRec5[1] = fRec5[0];
			fVec0[1] = fVec0[0];
			fRec6[1] = fRec6[0];
			fVec1[1] = fVec1[0];
			fRec7[1] = fRec7[0];
			fVec2[1] = fVec2[0];
			fRec8[1] = fRec8[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fVec3[1] = fVec3[0];
			fVec4[1] = fVec4[0];
			fVec5[1] = fVec5[0];
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
		}
	}

};

#endif
