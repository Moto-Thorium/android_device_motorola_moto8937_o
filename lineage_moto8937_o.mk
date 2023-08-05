#
# Copyright (C) 2021 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/product_launched_with_o.mk)

# Inherit some common LineageOS stuff.
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

# Kernel
TARGET_KERNEL_VERSION := 4.9

# Inherit from moto8937_o device
$(call inherit-product, device/motorola/moto8937_o/device.mk)

# Device identifier. This must come after all inclusions
PRODUCT_DEVICE := moto8937_o
PRODUCT_NAME := lineage_moto8937_o
BOARD_VENDOR := Motorola
PRODUCT_BRAND := Motorola
PRODUCT_MODEL := MSM8937 Oreo
PRODUCT_MANUFACTURER := Motorola
TARGET_VENDOR := Motorola

PRODUCT_GMS_CLIENTID_BASE := android-motorola
