# Makefile for vendor components

PRODUCT_PACKAGES += \
	vendor.gl.hardware.ledcontrol@1.0-service \
	LedControlService \
	LedControlApp

TARGET_FS_CONFIG_GEN += vendor/gl/hardware/interfaces/config.fs

DEVICE_MANIFEST_FILE += \
	vendor/gl/hardware/interfaces/manifest.xml

DEVICE_MATRIX_FILE += \
	vendor/gl/hardware/interfaces/compatibility_matrix.xml

BOARD_SEPOLICY_DIRS += vendor/gl/sepolicy
