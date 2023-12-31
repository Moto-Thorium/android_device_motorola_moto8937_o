/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_dalvik_heap.h>
#include <libinit_utils.h>
#include <libinit_variant.h>

#include "vendor_init.h"

#include <android-base/file.h>
#include <android-base/properties.h>

static const variant_info_t ahannah_info = {
    .brand = "motorola",
    .device = "ahannah",
    .marketname = "moto e5 plus",
    .model = "moto e5 plus",
    .build_fingerprint = "",

    .dpi = 280,
};

static const variant_info_t aljeter_info = {
    .brand = "motorola",
    .device = "aljeter",
    .marketname = "moto g(6) play",
    .model = "moto g(6) play",
    .build_fingerprint = "",

    .dpi = 280,
};

static const variant_info_t hannah_info = {
    .brand = "motorola",
    .device = "hannah",
    .marketname = "moto e5 plus",
    .model = "moto e5 plus",
    .build_fingerprint = "",

    .dpi = 280,
};

static const variant_info_t jeter_info = {
    .brand = "motorola",
    .device = "jeter",
    .marketname = "moto g(6) play",
    .model = "moto g(6) play",
    .build_fingerprint = "",

    .dpi = 280,
};

static const variant_info_t nora_info = {
    .brand = "motorola",
    .device = "nora",
    .marketname = "moto e5",
    .model = "moto e5",
    .build_fingerprint = "",

    .dpi = 280,
};

static void determine_variant()
{
    std::string variant;

    android::base::ReadFileToString("/sys/motorola-msm8937-mach/variant", &variant, true);
    if (variant.empty())
        return;
    variant.pop_back();

    if (variant == "ahannah")
        set_variant_props(ahannah_info);
    else if (variant == "aljeter")
        set_variant_props(aljeter_info);
    else if (variant == "hannah")
        set_variant_props(hannah_info);
    else if (variant == "jeter")
        set_variant_props(jeter_info);
    else if (variant == "nora")
        set_variant_props(nora_info);
}

static void set_model()
{
    std::string sku = android::base::GetProperty("ro.boot.hardware.sku", "");
    if (!sku.empty())
        set_ro_build_prop("model", sku, true);
}

void vendor_load_properties() {
    determine_variant();
    set_dalvik_heap();
    set_model();

    property_override("ro.secure", "0");
    property_override("ro.adb.secure", "0");
    property_override("ro.debuggable", "1");
    property_override("persist.sys.usb.config", "adb");
}
